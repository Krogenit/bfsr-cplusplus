#include <GLFW\glfw3.h>
#include <glm\vec2.hpp>
#include <glm\vec3.hpp>
#include <glm\vec4.hpp>
#include <iostream>
#include "TextureLoader.h"

using namespace std;
using namespace glm;

#pragma once
class TextureObject
{
public:
	GLuint *texture, list;
	vec2 origin;
	vec3 position, rotate, scale;
	vec4 color;

	static GLuint quadList;

	TextureObject();
	TextureObject(GLuint* texture, vec3 position, vec3 rotate, vec3 scale, vec4 color);
	TextureObject(Texture texture, vec3 position, vec3 rotate, vec4 color);

	void setOrigin(vec2 vec);

	TextureObject& TextureObject::operator=(const TextureObject& other);
	TextureObject(TextureObject const& object);

	static void loadPrimitives();
	virtual void update();
	virtual void render();


	~TextureObject();
};