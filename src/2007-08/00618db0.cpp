// from server: 100% by EspClaude
// from server: 51% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_claude_7acb92f76cdcf3d0.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise, off)
#define _MT 1
#define _DLL 1
#include <G3D/Vector3.h>
#include <G3D/CoordinateFrame.h>
#include "util/PV.h"
#include "util/Math.h"
#include "util/NormalId.h"

namespace RBX
{
	// 2007-08 Body: Body::updatePV (00530100) reads pv at +0x84, stateIndex at +0x80.
	class Body
	{
	private:
		char unknown[0x84];
		mutable PV pv;
		void updatePV() const;
	public:
		const RBX::PV& getPV() const
		{
			updatePV();
			return pv;
		}
	};

	class PairParams
	{
	public:
		G3D::Vector3 normal;
		union
		{
			float length;
			float rotation;
		};
		G3D::Vector3 position;
		float rotVel;
	};

	class GeoPair
	{
	private:
	struct GeoPairData
	{
		union
		{
			NormalId normalID0;
			float radius0;
		};
		union
		{
			NormalId normalID1;
			float radiusSum;
		};
		union
		{
			NormalId planeID;
			int point0ID;
		};
	};
	private:
		int geoPairType;
		const G3D::Vector3* offset0;
		const G3D::Vector3* offset1;
		Body* body0;
		Body* body1;
		float edgeLength0;
		GeoPairData pairData;
	public:
		void computeBallEdge(RBX::PairParams&);
	};

	G3D::Vector3 somemaththing(const G3D::Vector3& normal, const G3D::Vector3& trans)
	{
		float dot = normal.dot(trans);
		return trans - normal * dot;
	}

	void GeoPair::computeBallEdge(PairParams& _params)
	{
		const G3D::Vector3& body0PV = this->body0->getPV().position.translation;
		const G3D::CoordinateFrame& body1PV = this->body1->getPV().position;
		const G3D::Vector3& myoffset1 = *this->offset1;
		const G3D::Vector3& worldPoint = body1PV.pointToWorldSpace(myoffset1);

		const G3D::Vector3& normal = Math::getWorldNormal(this->pairData.normalID1, body1PV);

		const G3D::Vector3& temp = worldPoint - body0PV;
		_params.normal = somemaththing(normal, temp);
		_params.position = _params.normal + body0PV;
		_params.length = _params.normal.unitize() - this->pairData.radius0;
	}
}
