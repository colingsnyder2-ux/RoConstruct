#pragma float_control(precise, off, push)
#include "v8kernel/Link.h"
#include "v8kernel/Body.h"

// DUPLICATE: G3D::Matrix3::_mul 005137f0 is the verbatim G3D 6.09 library body (native-classes/G3DMatrix3.cpp line
// 1641). It compiled byte-exact here too; kept out of the build so the library body is not defined twice.
#if defined(LINK_DUPLICATE_BODIES_ENABLED)
// 005137f0
void G3D::Matrix3::_mul(const Matrix3& A, const Matrix3& B, Matrix3& out) {
    const float* ARowPtr = A.elt[0];
    float* outRowPtr     = out.elt[0];
        outRowPtr[0] =
            ARowPtr[0] * B.elt[0][0] +
            ARowPtr[1] * B.elt[1][0] +
            ARowPtr[2] * B.elt[2][0];
        outRowPtr[1] =
            ARowPtr[0] * B.elt[0][1] +
            ARowPtr[1] * B.elt[1][1] +
            ARowPtr[2] * B.elt[2][1];
        outRowPtr[2] =
            ARowPtr[0] * B.elt[0][2] +
            ARowPtr[1] * B.elt[1][2] +
            ARowPtr[2] * B.elt[2][2];

    ARowPtr       = A.elt[1];
    outRowPtr     = out.elt[1];

        outRowPtr[0] =
            ARowPtr[0] * B.elt[0][0] +
            ARowPtr[1] * B.elt[1][0] +
            ARowPtr[2] * B.elt[2][0];
        outRowPtr[1] =
            ARowPtr[0] * B.elt[0][1] +
            ARowPtr[1] * B.elt[1][1] +
            ARowPtr[2] * B.elt[2][1];
        outRowPtr[2] =
            ARowPtr[0] * B.elt[0][2] +
            ARowPtr[1] * B.elt[1][2] +
            ARowPtr[2] * B.elt[2][2];

    ARowPtr       = A.elt[2];
    outRowPtr     = out.elt[2];

        outRowPtr[0] =
            ARowPtr[0] * B.elt[0][0] +
            ARowPtr[1] * B.elt[1][0] +
            ARowPtr[2] * B.elt[2][0];
        outRowPtr[1] =
            ARowPtr[0] * B.elt[0][1] +
            ARowPtr[1] * B.elt[1][1] +
            ARowPtr[2] * B.elt[2][1];
        outRowPtr[2] =
            ARowPtr[0] * B.elt[0][2] +
            ARowPtr[1] * B.elt[1][2] +
            ARowPtr[2] * B.elt[2][2];
}
#endif

namespace RBX {
// 005989d0 (registry ?recoveredFrameMultiply@RBX@@YAXABVCoordinateFrame@G3D@@0AAV23@@Z, a synthetic descriptive name).
// GUARDED: the target calls the private static G3D::Matrix3::_mul 005137f0 directly (no alias check), so the real
// declaration was a Matrix3 friend/member; the installed G3D Matrix3.h (tools/rbxgs) grants no such access (C2248).
// Remaining blocker: the original declaration of 005989d0 (batch 32 park note). Enable once a header grants access.
void recoveredFrameMultiply(const G3D::CoordinateFrame& A, const G3D::CoordinateFrame& B, G3D::CoordinateFrame& out);
#if defined(LINK_MATRIX3_GRANTS_MUL_ACCESS)
#pragma float_control(precise, off, push)
void recoveredFrameMultiply(const G3D::CoordinateFrame& A, const G3D::CoordinateFrame& B, G3D::CoordinateFrame& out) {
 G3D::Matrix3::_mul(A.rotation,B.rotation,out.rotation);
 out.translation = A.pointToWorldSpace(B.translation);
}
#pragma float_control(pop)
#endif
}
using namespace RBX;

// DUPLICATES kept out of the build: Link() 00613d20 and RevoluteLink::computeChildInParent 00613cc0 are byte-exact in
// native-classes/Leaves2008RevoluteLink.cpp (also exact here), Link::dirty 00613cb0 is exact in
// native-classes/Inferred_00613cb0.cpp (this donor-Body copy is not: RBXASSERT and the donor Body layout).
#if defined(LINK_DUPLICATE_BODIES_ENABLED)
// 00613d20
Link::Link():body(NULL) {stateIndex = Body::getNextStateIndex();}
#endif

// 0047d410 (folded empty body)
Link::~Link()
{
}

#if defined(LINK_DUPLICATE_BODIES_ENABLED)
// 00613cb0
void Link::dirty()
{
	if (body)
	{
		RBXASSERT(body->getLink() == this);
		body->getRoot()->advanceStateIndex();
	}
}
#endif

// 00613d60: draft against the donor v8kernel/Body.h. The 2008 body calls Body::updatePV 00599360 on the parent
// (+0x14) and then reads parent stateIndex +0x90 (native-headers/v8kernel/Body2008.h layout); childInParent +0x98,
// stateIndex +0xc8. Not exact here (no candidate under the donor Body layout).
const G3D::CoordinateFrame& Link::getChildInParent() const
{
	int bodyStateIndex = body->getParent()->getStateIndex();

	if (stateIndex != bodyStateIndex)
	{
		computeChildInParent(childInParent);
		stateIndex = bodyStateIndex;
	}
	return childInParent;
}

#if defined(LINK_DUPLICATE_BODIES_ENABLED)
// 00613cc0
void RevoluteLink::computeChildInParent(G3D::CoordinateFrame& answer) const
{
    G3D::CoordinateFrame rotatedParentCoord(
        Math::rotateAboutZ(parentCoord.rotation, jointAngle), 
        parentCoord.translation);

    recoveredFrameMultiply(rotatedParentCoord, childCoordInverse, answer);
}
#endif

#pragma float_control(pop)
