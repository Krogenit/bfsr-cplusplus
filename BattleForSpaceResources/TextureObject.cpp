#include "TextureObject.h"

GLuint* texture;
vec2 origin;
vec3 position, rotate, scale;
vec4 color;

GLuint TextureObject::quadList;

TextureObject::TextureObject(GLuint* texture, vec3 position, vec3 rotate, vec3 scale, vec4 color)
{
	this->texture = texture;
	this->position = position;
	this->rotate = rotate;
	this->scale = scale;
	this->color = color;
}

TextureObject::TextureObject(Texture texture, vec3 position, vec3 rotate, vec4 color)
{
	this->texture = texture.texture;
	this->position = position;
	this->rotate = rotate;
	this->scale = vec3(texture.width, texture.height, 1);
	this->color = color;
}

TextureObject::TextureObject()
{
}

TextureObject::TextureObject(TextureObject const& other)
{
	texture = other.texture;
	origin = vec2(other.origin);
	position = vec3(other.position);
	rotate = vec3(other.rotate);
	scale = vec3(other.scale);
	color = vec4(other.color);
}

TextureObject& TextureObject::operator=(const TextureObject& other)
{
	if (this != &other) 
	{
		texture = other.texture;
		origin = vec2(other.origin);
		position = vec3(other.position);
		rotate = vec3(other.rotate);
		scale = vec3(other.scale);
		color = vec4(other.color);
	}
	return *this;
}

void TextureObject::setOrigin(vec2 vec)
{
	origin = vec;
}

void TextureObject::update()
{

}

void TextureObject::render()
{
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glRotatef(rotate.z, 0, 0, 1);
	glTranslatef(origin.x, origin.y, 0);
	glScalef(scale.x, scale.y, 1);
	glBindTexture(GL_TEXTURE_2D, *texture);
	glCallList(quadList);
	glPopMatrix();
}

void TextureObject::loadPrimitives()
{
	quadList = glGenLists(1);
	glNewList(quadList, GL_COMPILE);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 1);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0, 0);
	glVertex3d(0, 1, 0);
	glTexCoord2d(1, 0);
	glVertex3d(1, 1, 0);
	glTexCoord2d(1, 1);
	glVertex3d(1, 0, 0);
	glEnd();
	glEndList();
}


TextureObject::~TextureObject()
{

}
