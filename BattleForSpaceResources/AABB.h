#include <glm\vec2.hpp>

using namespace glm;

#pragma once
class AABB
{
public:
	vec2 min, max;

	AABB(vec2 min, vec2 max);
	AABB();
	AABB(AABB const& object);
	AABB& operator=(const AABB& other);

	bool isIntersects(vec2 vect);

	~AABB();
};

