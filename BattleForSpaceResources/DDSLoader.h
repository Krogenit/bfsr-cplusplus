#include <iostream>
#include <fstream>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/static_assert.hpp>

#pragma once
class DDSLoader
{
public:
	///////////////////////////////////////////////////////////////////////////////
	// RGBA
	///////////////////////////////////////////////////////////////////////////////
	struct RGBA
	{
		size_t w;
		size_t h;
		std::vector<unsigned char> buf;

		void resize(size_t _w, size_t _h)
		{
			w = _w;
			h = _h;
			buf.resize(w*h * 4);
			std::fill(buf.begin(), buf.end(), 0);
		}

		bool writePPM(const std::string &path)
		{
			std::ofstream io(path.c_str(), std::ios::binary);
			if (!io){
				std::cout << "fail to open: " << path << std::endl;
				return false;
			}

			io
				<< "P6\n"
				<< w << ' ' << h << '\n'
				<< 255 << '\n'
				;
			unsigned char *src = &buf[0];
			for (size_t y = 0; y<h; ++y){
				for (size_t x = 0; x<w; ++x, src += 4){
					io.write((char*)src, 3); // write rgb
				}
			}

			return true;
		}
	};
	typedef boost::shared_ptr<RGBA> RGBAPtr;

	static RGBAPtr load(const std::string &path);
};

