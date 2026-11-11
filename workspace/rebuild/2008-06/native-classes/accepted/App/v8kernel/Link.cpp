// >>> native-status (generated) -- do not edit >>>
// Link | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 93233d99 | roc native-status --write
#pragma float_control(precise, off, push)
#include "v8kernel/Link.h"
#include "v8kernel/Body.h"

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

namespace RBX {
#pragma float_control(precise, off, push)
void recoveredFrameMultiply(const G3D::CoordinateFrame& A, const G3D::CoordinateFrame& B, G3D::CoordinateFrame& out) {
 G3D::Matrix3::_mul(A.rotation,B.rotation,out.rotation);
 out.translation = A.pointToWorldSpace(B.translation);
}
#pragma float_control(pop)
}
using namespace RBX;

Link::Link():body(NULL) {stateIndex = Body::getNextStateIndex();}

Link::~Link()
{
}

void Link::dirty()
{
	if (body)
	{
		RBXASSERT(body->getLink() == this);
		body->getRoot()->advanceStateIndex();
	}
}

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

void RevoluteLink::computeChildInParent(G3D::CoordinateFrame& answer) const
{
    G3D::CoordinateFrame rotatedParentCoord(
        Math::rotateAboutZ(parentCoord.rotation, jointAngle), 
        parentCoord.translation);

    recoveredFrameMultiply(rotatedParentCoord, childCoordInverse, answer);
}

#pragma float_control(pop)
