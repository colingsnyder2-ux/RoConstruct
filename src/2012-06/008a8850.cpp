// from server: 69% by intel
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/Block.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/Block.h"

#include "decomp.h"
#include "util/Math.h"

#include <G3D/AABox.h>
#include <G3D/CollisionDetection.h>
#include <cstddef>
#include <functional>
#include <map>

namespace RBX {

using G3D::AABox;
using G3D::CollisionDetection;

static Vector3 vector3Abs(const Vector3& value)
{
	return Vector3(fabsf(value.x), fabsf(value.y), fabsf(value.z));
}

struct myLess : public std::binary_function<Vector3, Vector3, bool>
{
	// FUNCTION: WEBSERVICE 0x10109060
	bool operator()(const Vector3& a, const Vector3& b) const
	{
		if (a.x < b.x) {
			return true;
		}
		if (a.x > b.x) {
			return false;
		}
		if (a.y < b.y) {
			return true;
		}
		if (a.y > b.y) {
			return false;
		}
		if (a.z < b.z) {
			return true;
		}
		return false;
	}
};

// SIZE 0x60
class BlockTemplate
{
public:
	static const Vector3* getVertices(const Vector3& corner);

private:
	BlockTemplate(const Vector3& _corner);

	class BlockTemplates : public std::map<Vector3, BlockTemplate*, myLess>
	{
	public:
		~BlockTemplates();
	};

	static BlockTemplates blockTemplates;

	Vector3 vertices[8]; // 0x00
};

DECOMP_SIZE_ASSERT(BlockTemplate, 0x60)

// GLOBAL: WEBSERVICE 0x102fce48
BlockTemplate::BlockTemplates BlockTemplate::blockTemplates;

// STUB: WEBSERVICE 0x101090b0
Matrix3 Block::getMomentHollow(float mass) const
{
	float x = gridSize.x, y = gridSize.y, z = gridSize.z;

	float area = 2.0f * ((y + x) * z + y * x);

	Vector3 I(
		mass / (2 * area) *
			(z * z * y * x + z * y * y * y / 3 + z * z * z * x / 3 + z * y * y * x + y * y * y * x / 3 +
			 z * z * z * y / 3),
		mass / (2 * area) *
			(x * x * x * y / 3 + z * z * x * z / 3 + x * x * z * y + z * z * x * y + x * x * x * z / 3 +
			 z * z * z * y / 3),
		mass / (2 * area) *
			(y * y * y * z / 3 + y * x * x * z + y * x * x * x / 3 + y * y * z * x + x * x * x * z / 3 +
			 y * y * y * x / 3)
	);

	return Math::fromDiagonal(I);
}

// FUNCTION: WEBSERVICE 0x101091f0
float Block::getGridVolume() const
{
	return gridSize.z * gridSize.y * gridSize.x;
}

// FUNCTION: WEBSERVICE 0x10109200
const Vector3* Block::getEdgePoint(const Vector3int16& clip, NormalId& normalID) const
{
	if (clip.x == 0) {
		normalID = NORM_X;

		return &vertices[4 + 2 * (clip.y <= 0) + (clip.z <= 0)];
	}

	if (clip.y == 0) {
		normalID = NORM_Y;

		return &vertices[2 + 4 * (clip.x <= 0) + (clip.z <= 0)];
	}

	normalID = NORM_Z;

	return &vertices[2 * (2 * (clip.x <= 0) + (clip.y <= 0)) + 1];
}

// FUNCTION: WEBSERVICE 0x10109290
const Vector3* Block::getPlanePoint(const Vector3int16& clip, NormalId& normalID) const
{
	if (clip.x != 0) {
		normalID = clip.x > 0 ? NORM_X : NORM_X_NEG;

		return &vertices[4 * (clip.x <= 0)];
	}

	if (clip.y != 0) {
		normalID = clip.y > 0 ? NORM_Y : NORM_Y_NEG;

		return &vertices[2 * (clip.y <= 0)];
	}

	normalID = clip.z > 0 ? NORM_Z : NORM_Z_NEG;

	return &vertices[clip.z <= 0];
}

// FUNCTION: WEBSERVICE 0x10109330
GeoPairType Block::getBallBlockInfo(int onBorder, Vector3int16 clip, const Vector3*& offset, NormalId& normalID)
{
	if (onBorder == 1) {
		offset = getPlanePoint(clip, normalID);

		return BALL_PLANE_PAIR;
	}

	if (onBorder == 2) {
		offset = getEdgePoint(clip, normalID);

		return BALL_EDGE_PAIR;
	}

	offset = getCornerPoint(clip);

	return BALL_POINT_PAIR;
}

// FUNCTION: WEBSERVICE 0x101093c0
GeoPairType Block::getBallInsideInfo(const Vector3& ray, const Vector3*& offset, NormalId& normalID)
{
	float smallest = 1e30f;
	const Vector3& corner = *vertices;

	for (int i = 0; i < 3; i++) {
		float d = corner[i] - ray[i];

		if (smallest > d) {
			smallest = d;
			normalID = (NormalId) i;
		}

		d = ray[i] - corner[i];

		if (smallest > d) {
			smallest = d;
			normalID = (NormalId) (i + 3);
		}
	}

	offset = normalID > 2 ? &vertices[7] : vertices;

	return BALL_PLANE_PAIR;
}

// FUNCTION: WEBSERVICE 0x101094c0
void Block::projectToFace(Vector3& ray, Vector3int16& clip, int& onBorder)
{
	onBorder = 0;

	const Vector3& corner = *vertices;

	if (ray.x > corner.x) {
		ray.x = corner.x;
		onBorder++;
		clip.x = 1;
	}

	if (ray.x < -corner.x) {
		ray.x = -corner.x;
		onBorder++;
		clip.x = -1;
	}

	if (ray.y > corner.y) {
		ray.y = corner.y;
		onBorder++;
		clip.y = 1;
	}

	if (ray.y < -corner.y) {
		ray.y = -corner.y;
		onBorder++;
		clip.y = -1;
	}

	if (ray.z > corner.z) {
		ray.z = corner.z;
		onBorder++;
		clip.z = 1;
	}

	if (ray.z < -corner.z) {
		ray.z = -corner.z;
		onBorder++;
		clip.z = -1;
	}
}

// FUNCTION: WEBSERVICE 0x10109590
Vector2 Block::getProjectedVertex(const Vector3& vertex, NormalId normalID)
{
	Vector2 answer(0, 0);

	switch (normalID) {
	case NORM_X:
		answer.x = vertex.y;
		answer.y = vertex.z;
		break;
	case NORM_Y:
		answer.x = vertex.z;
		answer.y = vertex.x;
		break;
	case NORM_Z:
		answer.x = vertex.x;
		answer.y = vertex.y;
		break;
	case NORM_X_NEG:
		answer.x = vertex.z;
		answer.y = vertex.y;
		break;
	case NORM_Y_NEG:
		answer.x = vertex.x;
		answer.y = vertex.z;
		break;
	case NORM_Z_NEG:
		answer.x = vertex.y;
		answer.y = vertex.x;
		break;
	}

	return answer;
}

// STUB: WEBSERVICE 0x10109630
int Block::getClosestEdge(const Matrix3& rotation, NormalId normalID, Vector3& crossAxis)
{
	Vector3 axisInBody = crossAxis * rotation;

	Vector2 projected = getProjectedVertex(axisInBody, normalID);

	if (projected.y > 0) {
		if (projected.x > 0) {
			return normalID * 4;
		}

		return normalID * 4 + 1;
	}

	if (projected.x > 0) {
		return normalID * 4 + 3;
	}

	return normalID * 4 + 2;
}

// FUNCTION: WEBSERVICE 0x10109770
BlockTemplate::BlockTemplate(const Vector3& _corner)
{
	float x = -fabsf(_corner.x);
	float y = -fabsf(_corner.y);
	float z = -fabsf(_corner.z);

	for (int i = 0; i < 2; i++) {
		x = x * -1.0f;
		for (int j = 0; j < 2; j++) {
			y = y * -1.0f;
			for (int k = 0; k < 2; k++) {
				z = z * -1.0f;
				vertices[4 * i + 2 * j + k] = Vector3(x, y, z);
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x10109840
bool Block::hitTest(const Ray& rayInMe, Vector3& localHitPoint, bool& inside)
{
	Vector3 halfSize = gridSize * 0.5f;

	inside = false;

	bool hit = CollisionDetection::collisionLocationForMovingPointFixedAABox(
		rayInMe.origin,
		rayInMe.direction,
		AABox(-halfSize, halfSize),
		localHitPoint,
		inside
	);

	if (!inside) {
		return hit;
	}

	inside = false;

	Ray outsideRay = Ray::fromOriginAndDirection(rayInMe.origin - rayInMe.direction * 1000.0f, rayInMe.direction);

	CollisionDetection::collisionLocationForMovingPointFixedAABox(
		outsideRay.origin,
		outsideRay.direction,
		AABox(-halfSize, halfSize),
		localHitPoint,
		inside
	);

	return true;
}

// FUNCTION: WEBSERVICE 0x10109a70
Vector3 Block::getCenterToCorner(const Matrix3& rotation) const
{
	if (cornerRadius < 5.0f) {
		return Vector3(cornerRadius, cornerRadius, cornerRadius);
	}

	Vector3 maxValue = vector3Abs(rotation * vertices[0]);

	for (int i = 1; i < 4; i++) {
		maxValue = maxValue.max(vector3Abs(rotation * vertices[i]));
	}

	return maxValue;
}

// FUNCTION: WEBSERVICE 0x1010a5e0
const Vector3* BlockTemplate::getVertices(const Vector3& corner)
{
	BlockTemplates::iterator iter = blockTemplates.find(corner);

	if (iter != blockTemplates.end()) {
		return iter->second->vertices;
	}

	BlockTemplate* answer = new BlockTemplate(corner);
	blockTemplates[corner] = answer;

	return answer->vertices;
}

// FUNCTION: WEBSERVICE 0x1010a680
void Block::onSetSize()
{
	vertices = BlockTemplate::getVertices(gridSize * -0.5f);
	cornerRadius = vertices[0].magnitude();
}

// FUNCTION: WEBSERVICE 0x1010a6e0
BlockTemplate::BlockTemplates::~BlockTemplates()
{
	iterator iter = begin();

	while (iter != end()) {

		delete iter->second;
		iter++;
	}
}

} // namespace RBX
