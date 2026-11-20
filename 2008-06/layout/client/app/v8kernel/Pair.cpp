// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "v8world/GeoPair2008.h"
#include "util/Math.h"

namespace RBX
{
	GeoPair::GeoPair()
	{
		this->body0 = NULL;
		this->body1 = NULL;
		this->offset0 = NULL;
		this->offset1 = NULL;
	}

	void GeoPair::computeNormalPerpVel(float& normalVel, G3D::Vector3& perpVel, const PairParams& _params)
	{
		G3D::Vector3 body0Velocity = this->body0->getPVUnsafe().linearVelocityAtPoint(_params.position);
		G3D::Vector3 body1Velocity = this->body1->getPVUnsafe().linearVelocityAtPoint(_params.position);
		body1Velocity -= body0Velocity;

		float body1VelDot = _params.normal.dot(body1Velocity);
		normalVel = body1VelDot;
		G3D::Vector3 normalVelMul = _params.normal * body1VelDot;
		perpVel = body1Velocity - normalVelMul;
	}

	void GeoPair::forceToBodies(const G3D::Vector3& _force, const G3D::Vector3& _position)
	{
		this->body0->accumulateForce(-_force, _position);
		this->body1->accumulateForce(_force, _position);
	}

	void GeoPair::computeBallBall(PairParams& _params)
	{
		const PV& body0PV = this->body0->getPVUnsafe();
		const PV& body1PV = this->body1->getPVUnsafe();

		const G3D::Vector3& body0Trans = body0PV.position.translation;
		const G3D::Vector3& body1Trans = body1PV.position.translation;

		_params.normal = body1Trans - body0Trans;
		_params.length = _params.normal.unitize() - this->pairData.radiusSum;
		_params.position = _params.normal * this->pairData.radius0 + body0Trans;
	}

	void GeoPair::computeBallPoint(PairParams& _params)
	{
		const G3D::Vector3& pos0 = this->body0->getPVUnsafe().position.translation;
		const G3D::CoordinateFrame& coord1 = this->body1->getPVUnsafe().position;

		_params.position = coord1.pointToWorldSpace(*this->offset1);
		_params.normal = _params.position - pos0;
		_params.length = _params.normal.unitize() - this->pairData.radius0;
	}

	static G3D::Vector3 somemaththing(const G3D::Vector3& normal, const G3D::Vector3& trans)
	{
		return trans - normal * normal.dot(trans);
	}

	void GeoPair::computeBallEdge(PairParams& _params)
	{
		const G3D::Vector3& pos0 = this->body0->getPVUnsafe().position.translation;
		const G3D::CoordinateFrame& coord1 = this->body1->getPVUnsafe().position;

		G3D::Vector3 edgePoint = coord1.pointToWorldSpace(*this->offset1);
		G3D::Vector3 edge = Math::getWorldNormal(this->pairData.normalID1, coord1);
		G3D::Vector3 delta = edgePoint - pos0;

		_params.normal = delta - edge * delta.dot(edge);
		_params.position = pos0 + _params.normal;
		_params.length = _params.normal.unitize() - this->pairData.radius0;
	}

	void GeoPair::computeBallPlane(PairParams& _params)
	{
		const G3D::Vector3& pos0 = this->body0->getPVUnsafe().position.translation;
		const G3D::CoordinateFrame& coord1 = this->body1->getPVUnsafe().position;
		G3D::Vector3 planePoint = coord1.pointToWorldSpace(*this->offset1);

		_params.normal = -Math::getWorldNormal(this->pairData.normalID1, coord1);

		G3D::Vector3 delta = planePoint - pos0;
		G3D::Vector3 toPlane = _params.normal * delta.dot(_params.normal);

		_params.position = pos0 + toPlane;
		_params.length = toPlane.magnitude() - this->pairData.radius0;
	}

	void GeoPair::computePointPlane(RBX::PairParams& _params)
	{
		_params.position = this->body0->getPVUnsafe().position.pointToWorldSpace(*offset0);
		const G3D::CoordinateFrame& body1PV = this->body1->getPVUnsafe().position;
		G3D::Vector3 body1worldSpace = body1PV.pointToWorldSpace(*offset1);
		_params.normal = -Math::getWorldNormal(this->pairData.normalID1, body1PV);
		_params.length = _params.normal.dot(body1worldSpace - _params.position);
	}

	// is this actually an inline?
	__forceinline float unkClampInline(float d, float max)
	{
		if (fabs(d) > max)
			return max * Math::sign(d);

		return d;
	}
	
	void GeoPair::computeEdgeEdgePlane(RBX::PairParams& _params)
	{
		const G3D::CoordinateFrame& body0PV = this->body0->getPVUnsafe().position;
		const G3D::CoordinateFrame& body1PV = this->body1->getPVUnsafe().position;

		//world space defines
		G3D::Vector3 body0worldSpace = body0PV.pointToWorldSpace(*this->offset0);
		G3D::Vector3 body1worldSpace = body1PV.pointToWorldSpace(*this->offset1);
		//normals
		G3D::Vector3 body0Normal = Math::getWorldNormal(this->pairData.normalID0, body0PV);
		G3D::Vector3 body1Normal = Math::getWorldNormal(this->pairData.normalID1, body1PV);
		//calcs
		G3D::Vector3 bodyWorldSpaceDelta = body1worldSpace - body0worldSpace;
		float bodyNormalDot = body0Normal.dot(body1Normal);
		float compareResult = 1.0f - bodyNormalDot * bodyNormalDot;
		_params.normal = -Math::getWorldNormal(this->pairData.planeID, body1PV.rotation);
		if ( compareResult > 0.00001 )
		{
			float body1Dot = -bodyWorldSpaceDelta.dot(body1Normal);
			float body0Dot = bodyWorldSpaceDelta.dot(body0Normal);
			float theSinner = (body0Dot + (bodyNormalDot * body1Dot)) / compareResult;
			theSinner = unkClampInline(theSinner, 6.0f);
			_params.position = body0Normal * theSinner + body0worldSpace;
			_params.length = _params.normal.dot(body1worldSpace - _params.position);
		}
		else
		{
			_params.position = body0worldSpace;
			_params.length = 0.0;
		}
	}

	void GeoPair::computeEdgeEdge(RBX::PairParams& _params)
	{
		const G3D::CoordinateFrame& body0coord = this->body0->getPVUnsafe().position;
		const G3D::CoordinateFrame& body1coord = this->body1->getPVUnsafe().position;

		//world space defines
		G3D::Vector3 body0worldSpace = body0coord.pointToWorldSpace(*this->offset0);
		G3D::Vector3 body1worldSpace = body1coord.pointToWorldSpace(*this->offset1);
		//normals
		G3D::Vector3 body0Normal = Math::getWorldNormal(this->pairData.normalID0, body0coord);
		G3D::Vector3 body1Normal = Math::getWorldNormal(this->pairData.normalID1, body1coord);
		//calcs
		G3D::Vector3 bodyWorldSpaceDelta = body1worldSpace - body0worldSpace;
		float bodyNormalDot = body0Normal.dot(body1Normal);
		float body0Dot = bodyWorldSpaceDelta.dot(body0Normal);
		float body1Dot = -bodyWorldSpaceDelta.dot(body1Normal);
		float compareResult = 1.0f - bodyNormalDot * bodyNormalDot;
		if ( compareResult > 0.000001f )
		{
			float bodyDotCalc1 = (body0Dot + body1Dot * bodyNormalDot) * (1.0f / compareResult);
			float bodyDotCalc2 = (body1Dot + body0Dot * bodyNormalDot) * (1.0f / compareResult);
			const G3D::Vector3 body0NormalDotCalc = body0worldSpace + (body0Normal * bodyDotCalc1);
			const G3D::Vector3 body1NormalDotCalc = body1worldSpace + (body1Normal * bodyDotCalc2);
			_params.position = (body1NormalDotCalc + body0NormalDotCalc) * 0.5f;
			_params.normal = body0NormalDotCalc - body1NormalDotCalc;
			_params.length = -_params.normal.unitize();

			
		}
		else
		{
			_params.position = body0worldSpace;
			_params.normal = body0Normal;
			_params.length = 0.0f;
		}
	}
}
