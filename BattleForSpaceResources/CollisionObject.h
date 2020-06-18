//#ifndef BFSR_COLLISIONOBJECT
//#define BFSR_COLLISIONOBJECT
#define _USE_MATH_DEFINES
#include "TextureObject.h"
#include <glm\vec2.hpp>
#include <glm\geometric.hpp>
#include <cmath>

#pragma once
class CollisionObject : public TextureObject
{
public:
	static float gravity;

	float rotateSpeed, mass;
	vec2 velocity;

	CollisionObject(GLuint* texture, vec3 position, vec3 rotate, vec3 scale, vec4 color);
	CollisionObject();

	CollisionObject(CollisionObject const& object);

	CollisionObject& operator=(const CollisionObject& other);

	void setMass(float mass);
	void setRotationSpeed(float speed);
	void fixRotation();

	void rotateToVector(vec2 vector);
	void moveForward(float speed);
	virtual void update();
	virtual void render();

	~CollisionObject();
};

//#endif