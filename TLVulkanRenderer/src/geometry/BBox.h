#pragma once

#include "glm/glm.hpp"
#include <geometry/Geometry.h>

class BBox
{
public:
	typedef enum
	{
		X,
		Y,
		Z
	} EAxis;

	glm::vec3 min;
	glm::vec3 max;
	glm::vec3 centroid;
	Transform m_transform;

	Intersection GetIntersection(const Ray& r) const;

	static glm::vec3 Centroid(
		const glm::vec3& a,
		const glm::vec3& b
	);

	/**
	* \brief Generate a union bounding box from a and b
	* \param a : first bounding box
	* \param b : second bounding box
	* \return the union bounding box
	*/
	static BBox BBoxUnion(const BBox& a, const BBox& b);

	/**
	* \brief Return the maximum extent axis of the bounding box. This is used to sort the BVH tree
	* \param bbox
	* \return
	*/
	static EAxis BBoxMaximumExtent(const BBox& bbox);
};