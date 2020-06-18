#include "TextureLoader.h"

map<string, Texture> TextureLoader::textures;

void TextureLoader::loadTextures()
{
	ilutRenderer(ILUT_OPENGL);
	ilInit();
	iluInit();
	ilutInit();
	ilutRenderer(ILUT_OPENGL);

	loadTexture("backgound1", L"\\content\\textures\\ambient\\background\\background1.dds", 1920, 1080);
	loadTexture("human_small0", L"\\content\\textures\\entity\\ship\\human_small0.dds", 118, 118);

	loadTexture("bfsr_text2", L"\\content\\textures\\gui\\bfsr_text2.dds", 1553, 158);
	loadTexture("gui_buttonBase", L"\\content\\textures\\gui\\gui_buttonBase.dds", 300, 50);

	//*backgoundTexture = loadTexture(L"\\content\\textures\\ambient\\background\\background1.dds");
	//*shipTexture = loadTexture(L"\\content\\textures\\entity\\ship\\human_small0.dds");
}

void TextureLoader::loadTexture(string name, ILstring filename, int width, int height)
{
	Texture texture;
	texture.width = width;
	texture.height = height;
	texture.texture = new GLuint();
	wstring path(*(PathHelper::pathString));
	path.append(filename);
	wchar_t* pathChar = const_cast<wchar_t*>(path.c_str());
	*texture.texture = ilutGLLoadImage(pathChar);
	textures[name] = texture;
}
