#include "CollisionObject.h"

float CollisionObject::gravity;

float rotateSpeed, mass;
vec2 velocity;

CollisionObject::CollisionObject(GLuint* texture, vec3 position, vec3 rotate, vec3 scale, vec4 color)
: TextureObject(texture, position, rotate, scale, color)
{
	
}

CollisionObject::CollisionObject()
: TextureObject()
{
	
}

CollisionObject::CollisionObject(CollisionObject const& object)
: TextureObject(object)
{
	this->velocity = vec2(object.velocity);
	this->rotateSpeed = object.rotateSpeed;
	this->mass = object.mass;
}

CollisionObject& CollisionObject::operator=(const CollisionObject& other)
{
	if (this != &other)
	{
		TextureObject::operator=(other);
		this->rotateSpeed = other.rotateSpeed;
		this->velocity = vec2(other.velocity);
		this->mass = other.mass;
	}
	return *this;
}

void CollisionObject::setMass(float mass)
{
	this->mass = mass;
}

void CollisionObject::setRotationSpeed(float speed)
{
	this->rotateSpeed = speed;
}

void CollisionObject::moveForward(float speed)
{
	double rot = rotate.z / 180.0 * M_PI;
	vec2 acceleration = vec2(cos(rot), sin(rot)) / mass;

	vec2 newVelocity = vec2(velocity + acceleration);

	double velocityLength = length(velocity);

	if (length(newVelocity) > velocityLength)
	{
		double b = 1.0 - (velocityLength*velocityLength) / (speed*speed);

		if (b < 0)
			b = 0;

		double lorentz_factor = 1.0 / sqrt(b);
		acceleration.x /= lorentz_factor;
		acceleration.y /= lorentz_factor;
	}

	velocity += acceleration;
	velocityLength = length(velocity);

	if (velocityLength > 0)
	{
		newVelocity = normalize(newVelocity);
		velocity = newVelocity * (float)velocityLength;
	}
}

void CollisionObject::rotateToVector(vec2 vector)
{
	float mDx = vector.x - position.x;
	float mDy = vector.y - position.y;

	double rotateToObject = atan2(mDy, mDx) / M_PI * 180.0 + 180;
	rotateToObject = (rotateToObject < 0) ? rotateToObject + 360 : rotateToObject;
	double diff = rotateToObject - rotate.z;
	double absDiff = abs(diff);

	if ((diff >= 180.0 && diff < 360.0)
		|| (diff >= -180.0 && diff < 0.0))
	{
		if (absDiff >= 175 && absDiff < 185)
		{
			if (absDiff < 179 || absDiff > 181)
				rotate.z += rotateSpeed / 4.0;
		}
		else
			rotate.z += rotateSpeed;
	}
	else if ((diff >= 0.0 && diff < 180.0)
		|| (diff >= -360.0 && diff < -180.0))
	{
		if (absDiff >= 175 && absDiff < 185)
		{
			if (absDiff < 179 || absDiff > 181)
				rotate.z -= rotateSpeed / 4.0;
		}
		else
			rotate.z -= rotateSpeed;
	}

	fixRotation();
}

void CollisionObject::fixRotation()
{
	if (rotate.z > 360.0)
		rotate.z -= 360.0;
	else if (rotate.z < 0.0)
		rotate.z += 360.0;
}

void CollisionObject::update()
{
	TextureObject::update();

	float horiz = velocity.x;
	float vertic = velocity.y;
	velocity.x = horiz -= gravity * horiz;
	velocity.y = vertic -= gravity * vertic;

	position.x += velocity.x;
	position.y += velocity.y;
}

void CollisionObject::render()
{
	TextureObject::render();
}


CollisionObject::~CollisionObject()
{

}
