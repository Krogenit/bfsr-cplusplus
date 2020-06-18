#include "DDSLoader.h"


///////////////////////////////////////////////////////////////////////////////
// BinaryReader
///////////////////////////////////////////////////////////////////////////////
class BinaryReader
{
	std::istream &io_;

public:
	BinaryReader(std::istream &io)
		: io_(io)
	{}

	std::string getString(size_t size)
	{
		std::vector<char> buf(size);
		io_.read(&buf[0], size);
		return std::string(buf.begin(), buf.end());
	}

	void read(void *p, size_t size)
	{
		io_.read((char*)p, size);
	}

	template<typename T>
	T get()
	{
		T buf;
		io_.read((char*)&buf, sizeof(T));
		return buf;
	}
};

///////////////////////////////////////////////////////////////////////////////
// DDS struct
///////////////////////////////////////////////////////////////////////////////

// from ddraw.h
#define DDSD_CAPS               0x00000001l     // default
#define DDSD_HEIGHT             0x00000002l
#define DDSD_WIDTH              0x00000004l
#define DDSD_PITCH              0x00000008l
#define DDSD_PIXELFORMAT        0x00001000l
#define DDSD_LINEARSIZE         0x00080000l

#define DDPF_ALPHAPIXELS                        0x00000001l
#define DDPF_FOURCC                             0x00000004l
#define DDPF_RGB                                0x00000040l

typedef unsigned int DWORD;

struct DDPIXELFORMAT
{
	DWORD    dwSize;
	DWORD    dwFlags;
	DWORD    dwFourCC;
	union
	{
		DWORD    dwRGBBitCount;
		DWORD    dwYUVBitCount;
		DWORD    dwZBufferBitDepth;
		DWORD    dwAlphaBitDepth;
	};
	union
	{
		DWORD    dwRBitMask;
		DWORD    dwYBitMask;
	};
	union
	{
		DWORD    dwGBitMask;
		DWORD    dwUBitMask;
	};
	union{
		DWORD    dwBBitMask;
		DWORD    dwVBitMask;
	};
	union
	{
		DWORD    dwRGBAlphaBitMask;
		DWORD    dwYUVAlphaBitMask;
	};
}
#ifdef __GNUG__
__attribute__((packed))
#endif
;
BOOST_STATIC_ASSERT(sizeof(DDPIXELFORMAT) == 32);

struct DDSCAPS2
{
	DWORD dwCaps1;
	DWORD dwCaps2;
	DWORD Reserved[2];
}
#ifdef __GNUG__
__attribute__((packed))
#endif
;
BOOST_STATIC_ASSERT(sizeof(DDSCAPS2) == 16);

struct DDSURFACEDESC2
{
	DWORD dwSize;
	DWORD dwFlags;
	DWORD dwHeight;
	DWORD dwWidth;
	DWORD dwPitchOrLinearSize;
	DWORD dwDepth;
	DWORD dwMipMapCount;
	DWORD dwReserved1[11];
	DDPIXELFORMAT ddpfPixelFormat;
	DDSCAPS2 ddsCaps;
	DWORD dwReserved2;
}
#ifdef __GNUG__
__attribute__((packed))
#endif
;
BOOST_STATIC_ASSERT(sizeof(DDSURFACEDESC2) == 124);
#ifdef _MSC_VER
#pragma pack( pop )
#endif

///////////////////////////////////////////////////////////////////////////////
// load dds file
///////////////////////////////////////////////////////////////////////////////
DDSLoader::RGBAPtr DDSLoader::load(const std::string &path)
{
	RGBAPtr image;

	std::ifstream io(path.c_str(), std::ios::binary);
	if (!io){
		return image;
	}

	BinaryReader reader(io);

	// magic number
	if (reader.getString(4) != "DDS "){
		return image;
	}

	// DDSURFACEDESC2
	DDSURFACEDESC2 header = reader.get<DDSURFACEDESC2>();
	assert(header.dwSize == 124);

	if (header.ddpfPixelFormat.dwFlags & DDPF_RGB){
		image = RGBAPtr(new RGBA);
		image->resize(header.dwWidth, header.dwHeight);
		size_t pitch = header.dwWidth * header.ddpfPixelFormat.dwRGBBitCount / 8;

		std::cout
			<< "<normal image>" << std::endl
			<< "BitCount: " << header.ddpfPixelFormat.dwRGBBitCount << std::endl
			;
		// normal
		if (header.dwFlags & DDSD_PITCH){
			std::cout << "specified line pitch" << std::endl;
			pitch = header.dwPitchOrLinearSize;
		}

		switch (header.ddpfPixelFormat.dwRGBBitCount)
		{
		case 32:
		{
				   assert(header.ddpfPixelFormat.dwRBitMask == 0x00ff0000);
				   assert(header.ddpfPixelFormat.dwGBitMask == 0x0000ff00);
				   assert(header.ddpfPixelFormat.dwBBitMask == 0x000000ff);
				   if (header.ddpfPixelFormat.dwFlags & DDPF_ALPHAPIXELS){
					   std::cout << "has alpha channel" << std::endl;
					   assert(header.ddpfPixelFormat.dwRGBAlphaBitMask == 0xff000000);
				   }
				   unsigned char *dst = &image->buf[0];
				   std::vector<unsigned char> pitchBuffer(pitch);
				   for (size_t y = 0; y<header.dwHeight; ++y){
					   reader.read(&pitchBuffer[0], pitch);
					   unsigned char *src = &pitchBuffer[0];
					   for (size_t x = 0; x<header.dwWidth; ++x, dst += 4, src += 4){
						   dst[0] = src[2]; // R
						   dst[1] = src[1]; // G
						   dst[2] = src[0]; // B
						   dst[3] = src[3]; // A
					   }
				   }
		}
			break;

		default:
			std::cout << "not implemented: "
				<< header.ddpfPixelFormat.dwRGBBitCount << std::endl;
			break;
		}
	}
	else if (header.ddpfPixelFormat.dwFlags & DDPF_FOURCC){
		// compress image
		std::cout
			<< "compress: " << header.ddpfPixelFormat.dwFourCC << std::endl;
	}
	else{
		std::cout << "invalid header." << std::endl;
		assert(false);
	}

	return image;
}
