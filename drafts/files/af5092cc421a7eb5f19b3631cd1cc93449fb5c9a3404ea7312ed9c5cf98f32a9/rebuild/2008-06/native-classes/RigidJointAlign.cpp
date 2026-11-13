// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 RBX::RigidJoint methods that read the native Primitive (inactive): isAligned 00645870, align 006458d0 and
// faceIdToCoords 00645980. getChildInParent 00645930 lives in WorldJointRigid.cpp.
//
// Primitive is redeclared unit-locally (pattern of ContactUnit2008ConnectorBody.cpp): the part-embedded
// v8world/Primitive.h includes the donor v8world/RigidJoint.h, which cannot be declared next to
// v8world/Joints2008.h. Only the two out-of-line members called here are declared, with the declarations of
// part-embedded/v8world/Primitive.h: getCoordinateFrame 005e82c0 and getFaceCoordInObject 005e7680.
#include "v8world/Joints2008.h"
#include "util/Math.h"

namespace RBX
{
	class Primitive
	{
	public:
		__declspec(noinline) const G3D::CoordinateFrame& getCoordinateFrame() const;   // 005e82c0
		G3D::CoordinateFrame getFaceCoordInObject(NormalId objectFace);                 // 005e7680
	};

	// 00645870: CoordinateFrame::operator* 00476700, Math::fuzzyEq(CoordinateFrame) 005de2a0, 1e-5f 0082b3b0
	bool RigidJoint::isAligned()
	{
		G3D::CoordinateFrame c0 = getPrimitive(0)->getCoordinateFrame() * jointCoord0;
		G3D::CoordinateFrame c1 = getPrimitive(1)->getCoordinateFrame() * jointCoord1;
		return Math::fuzzyEq(c0, c1, 1e-5f, 1e-5f);
	}

	// 006458d0: CoordinateFrame::inverse 00478330
	G3D::CoordinateFrame RigidJoint::align(Primitive* pMove, Primitive* pStay)
	{
		const G3D::CoordinateFrame& cMove = getJointCoord(pMove == getPrimitive(0) ? 0 : 1);
		const G3D::CoordinateFrame& cStay = getJointCoord(pStay == getPrimitive(0) ? 0 : 1);
		G3D::CoordinateFrame jointWorld = pStay->getCoordinateFrame() * cStay;
		return jointWorld * cMove.inverse();
	}

	// 00645980: Primitive::getFaceCoordInObject 005e7680, CoordinateFrame::toObjectSpace 0060e8f0 (nId1 unused)
	void RigidJoint::faceIdToCoords(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1,
	                                G3D::CoordinateFrame& c0, G3D::CoordinateFrame& c1)
	{
		c0 = p0->getFaceCoordInObject(nId0);
		G3D::CoordinateFrame jointInWorld = p0->getCoordinateFrame() * c0;
		c1 = p1->getCoordinateFrame().toObjectSpace(jointInWorld);
	}
}
