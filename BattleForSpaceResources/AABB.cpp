#include "AABB.h"

vec2 min, max;

AABB::AABB(vec2 min, vec2 max)
{
	this->min = min;
	this->max = max;
}

AABB::AABB()
{

}

AABB::AABB(AABB const& object)
{
	this->min = vec2(object.min);
	this->max = vec2(object.max);
}

AABB& AABB::operator=(const AABB& other)
{
	if (this != &other)
	{
		this->min = vec2(other.min);
		this->max = vec2(other.max);
	}
	return *this;
}

bool AABB::isIntersects(vec2 vect)
{
	return vect.x >= min.x && vect.x < max.x && vect.y >= min.y && vect.y < max.y;
}

AABB::~AABB()
{
}
