// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/util/Extents.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Extents.h"

#include "util/Math.h"

namespace RBX {

// FUNCTION: WEBSERVICE 0x100a59a0
NormalId Extents::closestFace(const Vector3& point)
{
	const float xHigh = fabsf(point.x - high.x);
	const float yHigh = fabsf(point.y - high.y);
	const float zHigh = fabsf(point.z - high.z);
	const float xLow = fabsf(point.x - low.x);
	const float yLow = fabsf(point.y - low.y);
	const float zLow = fabsf(point.z - low.z);

	NormalId answer = NORM_X;
	float closest = xHigh;

	if (yHigh < closest) {
		closest = yHigh;
		answer = NORM_Y;
	}
	if (zHigh < closest) {
		closest = zHigh;
		answer = NORM_Z;
	}
	if (xLow < closest) {
		closest = xLow;
		answer = NORM_X_NEG;
	}
	if (yLow < closest) {
		closest = yLow;
		answer = NORM_Y_NEG;
	}
	if (zLow < closest) {
		closest = zLow;
		answer = NORM_Z_NEG;
	}

	return answer;
}

// FUNCTION: WEBSERVICE 0x100a5a40
float Extents::areaXZ() const
{
	return (high.x - low.x) * (high.z - low.z);
}

// FUNCTION: WEBSERVICE 0x100a5a50
Vector3 Extents::getCorner(int i) const
{
	const Vector3* corners = &low;

	return Vector3(corners[i / 4].x, corners[i / 2 % 2].y, corners[i % 2].z);
}

// FUNCTION: WEBSERVICE 0x100a5ab0
void Extents::getFaceCorners(NormalId faceId, Vector3& v0, Vector3& v1, Vector3& v2, Vector3& v3) const
{
	switch (faceId) {
	case NORM_X:
		goto x;
	case NORM_Y:
		goto y;
	case NORM_Z:
		goto z;
	case NORM_X_NEG:
		goto xNeg;
	case NORM_Y_NEG:
		goto yNeg;
	case NORM_Z_NEG:
		goto zNeg;
	}

	return;

x:
	v0 = getCorner(4), v1 = getCorner(6), v2 = getCorner(7), v3 = getCorner(5);
	return;

y:
	v0 = getCorner(2), v1 = getCorner(3), v2 = getCorner(7), v3 = getCorner(6);
	return;

z:
	v0 = getCorner(1), v1 = getCorner(5), v2 = getCorner(7), v3 = getCorner(3);
	return;

xNeg:
	v0 = getCorner(0), v1 = getCorner(1), v2 = getCorner(3), v3 = getCorner(2);
	return;

yNeg:
	v0 = getCorner(0), v1 = getCorner(4), v2 = getCorner(5), v3 = getCorner(1);
	return;

zNeg:
	v0 = getCorner(0), v1 = getCorner(2), v2 = getCorner(6), v3 = getCorner(4);
	return;
}

// FUNCTION: WEBSERVICE 0x100a5d20
bool Extents::overlapsOrTouches(const Extents& other) const
{
	if (!(low.x > other.high.x) && !(low.y > other.high.y) && !(low.z > other.high.z) && !(high.y < other.low.y) &&
		!(high.x < other.low.x) && !(high.z < other.low.z)) {
		return true;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100a5d80
bool Extents::separatedByMoreThan(const Extents& other, float distance) const
{
	Extents thisExpanded(*this);
	thisExpanded.expand(distance);

	return !thisExpanded.overlapsOrTouches(other);
}

// FUNCTION: WEBSERVICE 0x100a5de0
bool Extents::contains(const Vector3& point) const
{
	return point.x >= low.x && point.y >= low.y && point.z >= low.z && point.x <= high.x && point.y <= high.y &&
		   point.z <= high.z;
}

// FUNCTION: WEBSERVICE 0x100a5e40
bool Extents::fuzzyContains(const Vector3& point, float slop) const
{
	return low.x - slop <= point.x && low.y - slop <= point.y && low.z - slop <= point.z && point.x <= high.x + slop &&
		   point.y <= high.y + slop && point.z <= slop + high.z;
}

// FUNCTION: WEBSERVICE 0x100a5eb0
const Extents& Extents::zero()
{
	static const Extents e(Vector3::zero(), Vector3::zero());

	return e;
}

// FUNCTION: WEBSERVICE 0x100a5f70
const Extents& Extents::negativeInfiniteExtents()
{
	static const Extents e;

	return e;
}

// FUNCTION: WEBSERVICE 0x100a5fd0
Vector3 Extents::faceCenter(NormalId faceId) const
{
	Vector3 answer = (high + low) * 0.5f;

	const int axis = faceId % 3;
	answer[axis] = faceId < 3 ? high[axis] : low[axis];

	return answer;
}

// FUNCTION: WEBSERVICE 0x100a6040
bool Extents::containedByFrustum(const G3D::GCamera::Frustum& frustum) const
{
	for (int i = 0; i < frustum.faceArray.size(); ++i) {
		const Plane& plane = frustum.faceArray[i].plane;

		for (int j = 0; j < 8; ++j) {
			const Vector3 corner = getCorner(j);

			if (!plane.halfSpaceContains(corner)) {
				return false;
			}
		}
	}

	return true;
}

// FUNCTION: WEBSERVICE 0x100a6100
Extents Extents::vv(const Vector3& v0, const Vector3& v1)
{
	Extents answer;
	answer.low = v0.min(v1);
	answer.high = v0.max(v1);

	return answer;
}

// FUNCTION: WEBSERVICE 0x100a61d0
Extents Extents::express(const CoordinateFrame& myFrame, const CoordinateFrame& expressInFrame)
{
	Vector3 minC(Math::inf(), Math::inf(), Math::inf());
	Vector3 maxC(-Math::inf(), -Math::inf(), -Math::inf());

	for (int i = 0; i < 8; ++i) {
		const Vector3 inOther = expressInFrame.pointToObjectSpace(myFrame.pointToWorldSpace(getCorner(i)));

		minC = minC.min(inOther);
		maxC = maxC.max(inOther);
	}

	return vv(minC, maxC);
}

// FUNCTION: WEBSERVICE 0x100a6440
Extents Extents::toWorldSpace(const CoordinateFrame& localCoord)
{
	Vector3 minC(Math::inf(), Math::inf(), Math::inf());
	Vector3 maxC(-Math::inf(), -Math::inf(), -Math::inf());

	for (int i = 0; i < 8; ++i) {
		const Vector3 world = localCoord.pointToWorldSpace(getCorner(i));

		minC = minC.min(world);
		maxC = maxC.max(world);
	}

	return vv(minC, maxC);
}

// FUNCTION: WEBSERVICE 0x100a6660
Plane Extents::getPlane(NormalId normalId) const
{
	const Vector3 point = faceCenter(normalId);
	const Vector3 normal = normalIdToVector3(normalId);

	return Plane(normal, point);
}

} // namespace RBX
