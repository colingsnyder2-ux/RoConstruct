#pragma once
// >>> native-status (generated) -- do not edit >>>
// GeoPair2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src d66b2bca | roc native-status --write
// 2008-06 native RBX::GeoPair / PairParams / GeoPairType on the 2008 Body of native-headers/v8kernel/Body2008.h
// (inactive). Declared under a non-colliding name (the original declaration is the donor v8kernel/Pair.h, which
// includes the donor v8kernel/Body.h and is reached through native-headers/v8kernel/Connector2008.h); a unit must not
// include both this header and the donor v8kernel/Pair.h. GeoPair only holds Body pointers, so its layout does not
// depend on the Body layout; it is the donor one:
//   size     0x24: ContactConnector() 00606d40 constructs it at +0x8 (GeoPair() 00613060) and frictionOffset follows
//            at +0x44 after the floats +0x2c..+0x40.
//   fields   geoPairType +0x0, offset0 +0x4, offset1 +0x8, body0 +0xc, body1 +0x10, edgeLength0 +0x14, pair data
//            +0x18 / +0x1c / +0x20 (normalID0 or radius0, normalID1 or radiusSum, planeID or point0ID).
//   match    00606a50 (evidence name ?match@GeoPair@RBX@@QAE_NPAVBody@2@0W4GeoPairType@2@HH@Z, out of line, `ret 0x14`):
//            POINT_PLANE (4) compares body0 / body1 +0xc / +0x10, point0ID +0x20 and normalID1 +0x1c; EDGE_EDGE_PLANE (5)
//            normalID0 +0x18 and normalID1 +0x1c; otherwise both orders of the body / normal pairs.
//   getBody  ContactConnector::getBody 00606230 / canThrottle 00606250 read body0 / body1 at connector +0x14 / +0x18.
#include <G3D/Vector3.h>
#include "v8kernel/Body2008.h"
#include "util/NormalId.h"

struct NativeBodyPrimitive2008Layout;

namespace RBX
{
	enum GeoPairType
	{
		BALL_BALL_PAIR = 0,
		BALL_POINT_PAIR = 1,
		BALL_EDGE_PAIR = 2,
		BALL_PLANE_PAIR = 3,
		POINT_PLANE_PAIR = 4,
		EDGE_EDGE_PLANE_PAIR = 5,
		EDGE_EDGE_PAIR = 6
	};

	// PairParams (0x20): ContactConnector::computeForce 00606780 zeroes normal +0x0 / position +0x10 of its local (length
	// +0xc and rotVel +0x1c are left unset) before the compute* call, then reads length +0xc, normal and position.
	class PairParams
	{
	public:
		G3D::Vector3 normal;                              // +0x0
		union
		{
			float length;                                 // +0xc
			float rotation;
		};
		G3D::Vector3 position;                            // +0x10
		float rotVel;                                     // +0x1c

	public:
		PairParams()
			: normal(0, 0, 0),
			  position(0, 0, 0)
		{
		}
	};

	class GeoPair
	{
		friend struct ::NativeBodyPrimitive2008Layout;

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
		GeoPairType geoPairType;                          // +0x0
		const G3D::Vector3* offset0;                      // +0x4
		const G3D::Vector3* offset1;                      // +0x8
		Body* body0;                                      // +0xc
		Body* body1;                                      // +0x10
		float edgeLength0;                                // +0x14
		GeoPairData pairData;                             // +0x18

	private:
		// the GeoPair unit 00613060..00613cb0; ContactConnector::computeForce 00606780 dispatches on geoPairType through
		// the jump table 00606a34 (0 -> 00613290, 1 -> 006131e0, 2 -> 00613320, 3 -> 00613440, 4 -> 00613560,
		// 5 -> 006136a0, 6 -> 006139c0) in the case order of computeLengthNormalPosition below.
		void computeBallBall(PairParams& _params);        // 00613290
		void computeBallPoint(PairParams& _params);       // 006131e0
		void computeBallEdge(PairParams& _params);        // 00613320
		void computeBallPlane(PairParams& _params);       // 00613440
		void computePointPlane(PairParams& _params);      // 00613560
		void computeEdgeEdgePlane(PairParams& _params);   // 006136a0
		void computeEdgeEdge(PairParams& _params);        // 006139c0

	public:
		GeoPair();                                        // 00613060

		void computeLengthNormalPosition(PairParams& _params)
		{
			switch (geoPairType)
			{
			case POINT_PLANE_PAIR:
				computePointPlane(_params);
				break;
			case EDGE_EDGE_PLANE_PAIR:
				computeEdgeEdgePlane(_params);
				break;
			case BALL_BALL_PAIR:
				computeBallBall(_params);
				break;
			case BALL_PLANE_PAIR:
				computeBallPlane(_params);
				break;
			case BALL_POINT_PAIR:
				computeBallPoint(_params);
				break;
			case BALL_EDGE_PAIR:
				computeBallEdge(_params);
				break;
			case EDGE_EDGE_PAIR:
				computeEdgeEdge(_params);
				break;
			}
		}
		void computeNormalPerpVel(float& normalVel, G3D::Vector3& perpVel, const PairParams& _params);   // 006130e0
		void forceToBodies(const G3D::Vector3& _force, const G3D::Vector3& _position);                 // 00613080

		Body* getBody(int i)
		{
			return i == 0 ? body0 : body1;
		}
		const Body* getBody(int i) const
		{
			return i == 0 ? body0 : body1;
		}

		bool match(Body* _b0, Body* _b1, GeoPairType _pairType, int param0, int param1);   // 00606a50
	};
}
