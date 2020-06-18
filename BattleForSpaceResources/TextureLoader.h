#ifndef BFSR_TEXTURELOADER
#define BFSR_TEXTURELOADER

#include <IL\ilut.h>
#include "PathHelper.h"
#include <map>
#include <string>

#pragma once

struct Texture
{
public:
	GLuint* texture;
	int width, height;
};

class TextureLoader
{
public:
	static map<string, Texture> textures;

	static void loadTextures();
	static void loadTexture(string name, ILstring filename, int width, int height);

};

#endif