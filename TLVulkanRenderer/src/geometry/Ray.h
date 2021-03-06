#pragma once
#include <glm/glm.hpp>

const float COST_TRAVERSAL = 0.125f;
const float COST_INTERSECTION = 1.0f;

class Ray
{
public:
	glm::vec3 m_origin;
	glm::vec3 m_direction;
	float m_traversalCost;

	Ray() : m_origin(glm::vec3(0)), m_direction(glm::vec3(0)), m_traversalCost(0.0f) {}

	Ray(glm::vec3 origin, glm::vec3 direction) :
		m_origin(origin), m_direction(direction), m_traversalCost(0.0f)
	{}

	Ray GetTransformedCopy(glm::mat4 transform) const {

		glm::vec4 origin = transform * glm::vec4(m_origin, 1);
		glm::vec4 direction = transform * glm::vec4(m_direction, 0);

		return Ray(origin, direction);
	}

	glm::vec3 GetPointOnRay(float t) const {
		return m_origin + m_direction * t;
	}
};


