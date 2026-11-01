// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8kernel/Pair.cpp

// Candidate translation unit (score above; library headers required).
#include "v8kernel/Pair.h"

#include "decomp.h"
#include "util/Math.h"
#include "util/Velocity.h"
#include "v8kernel/Body.h"

#include <cstddef>

namespace RBX {

// FUNCTION: WEBSERVICE 0x1011cfc0
GeoPair::GeoPair() : body0(NULL), body1(NULL), offset0(NULL), offset1(NULL)
{
}

// FUNCTION: WEBSERVICE 0x1011cfe0
void GeoPair::forceToBodies(const Vector3& _force, const Vector3& _position)
{
	body0->accumulateForce(-_force, _position);
	body1->accumulateForce(_force, _position);
}

// FUNCTION: WEBSERVICE 0x1011d040
void GeoPair::computeNormalPerpVel(float& normalVel, Vector3& perpVel, const PairParams& _params)
{
	Vector3 v0 = body0->getPV().linearVelocityAtPoint(_params.position);
	Vector3 v1 = body1->getPV().linearVelocityAtPoint(_params.position);

	Vector3 vel = v1 - v0;

	normalVel = _params.normal.dot(vel);

	perpVel = vel - _params.normal * normalVel;
}

// FUNCTION: WEBSERVICE 0x1011d1a0
void GeoPair::computeBallBall(PairParams& _params)
{
	const Vector3& pos0 = body0->getPos();
	const Vector3& pos1 = body1->getPos();

	_params.normal = pos1 - pos0;
	_params.length = _params.normal.unitize() - pairData.radiusSum;
	_params.position = pos0 + _params.normal * pairData.radius0;
}

// FUNCTION: WEBSERVICE 0x1011d240
void GeoPair::computeBallPoint(PairParams& _params)
{
	const Vector3& pos0 = body0->getPos();
	const CoordinateFrame& coord1 = body1->getCoordinateFrame();

	_params.position = coord1.pointToWorldSpace(*offset1);
	_params.normal = _params.position - pos0;
	_params.length = _params.normal.unitize() - pairData.radius0;
}

// FUNCTION: WEBSERVICE 0x1011d320
void GeoPair::computeBallEdge(PairParams& _params)
{
	const Vector3& pos0 = body0->getPos();
	const CoordinateFrame& coord1 = body1->getCoordinateFrame();

	Vector3 edgePoint = coord1.pointToWorldSpace(*offset1);

	Vector3 edge = Math::getWorldNormal(pairData.normalID1, coord1);

	Vector3 delta = edgePoint - pos0;

	_params.normal = delta - edge * delta.dot(edge);

	_params.position = pos0 + _params.normal;
	_params.length = _params.normal.unitize() - pairData.radius0;
}

// FUNCTION: WEBSERVICE 0x1011d480
void GeoPair::computeBallPlane(PairParams& _params)
{
	const Vector3& pos0 = body0->getPos();
	const CoordinateFrame& coord1 = body1->getCoordinateFrame();
	Vector3 planePoint = coord1.pointToWorldSpace(*offset1);

	_params.normal = -Math::getWorldNormal(pairData.normalID1, coord1);

	Vector3 delta = planePoint - pos0;

	Vector3 toPlane = _params.normal * delta.dot(_params.normal);

	_params.position = pos0 + toPlane;
	_params.length = toPlane.magnitude() - pairData.radius0;
}

// FUNCTION: WEBSERVICE 0x1011d5e0
void GeoPair::computePointPlane(PairParams& _params)
{
	_params.position = body0->getCoordinateFrame().pointToWorldSpace(*offset0);

	const CoordinateFrame& coord1 = body1->getCoordinateFrame();

	Vector3 planePoint = coord1.pointToWorldSpace(*offset1);

	_params.normal = -Math::getWorldNormal(pairData.normalID1, coord1);

	_params.length = (planePoint - _params.position).dot(_params.normal);
}

// FUNCTION: WEBSERVICE 0x1011d770
void GeoPair::computeEdgeEdgePlane(PairParams& _params)
{
	const CoordinateFrame& coord0 = body0->getCoordinateFrame();
	const CoordinateFrame& coord1 = body1->getCoordinateFrame();

	Vector3 p0 = coord0.pointToWorldSpace(*offset0);
	Vector3 p1 = coord1.pointToWorldSpace(*offset1);

	Vector3 e0 = Math::getWorldNormal(pairData.normalID0, coord0);
	Vector3 e1 = Math::getWorldNormal(pairData.normalID1, coord1);

	Vector3 delta = p1 - p0;

	float dot = e1.dot(e0);
	float denom = 1.0f - dot * dot;

	_params.normal = -Math::getWorldNormal(pairData.planeID, coord1);

	if (denom > 1e-05) {
		float t0 = delta.dot(e0);
		float t1 = -delta.dot(e1);

		float t = (t1 * dot + t0) / denom;

		if (6.0f < fabs(t)) {
			t = 6.0f * Math::sign(t);
		}

		_params.position = p0 + e0 * t;
		_params.length = (p1 - _params.position).dot(_params.normal);
	}
	else {
		_params.position = p0;
		_params.length = 0.0f;
	}
}

// FUNCTION: WEBSERVICE 0x1011daf0
void GeoPair::computeEdgeEdge(PairParams& _params)
{
	const CoordinateFrame& coord0 = body0->getCoordinateFrame();
	const CoordinateFrame& coord1 = body1->getCoordinateFrame();

	Vector3 p0 = coord0.pointToWorldSpace(*offset0);
	Vector3 p1 = coord1.pointToWorldSpace(*offset1);

	Vector3 e0 = Math::getWorldNormal(pairData.normalID0, coord0);
	Vector3 e1 = Math::getWorldNormal(pairData.normalID1, coord1);

	Vector3 delta = p1 - p0;

	float dot = e1.dot(e0);
	float t0 = delta.dot(e0);
	float t1 = -e1.dot(delta);

	float denom = 1.0f - dot * dot;

	if (denom > 1e-06f) {
		float recip = 1.0f / denom;

		float s0 = (t1 * dot + t0) * recip;
		float s1 = (t0 * dot + t1) * recip;

		Vector3 c0 = p0 + e0 * s0;
		Vector3 c1 = p1 + e1 * s1;

		_params.position = (c1 + c0) * 0.5f;
		_params.normal = c0 - c1;
		_params.length = -_params.normal.unitize();
	}
	else {
		_params.position = p0;
		_params.normal = e0;
		_params.length = 0.0f;
	}
}

} // namespace RBX
