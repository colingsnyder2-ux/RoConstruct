// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// >>> native-status (generated) -- do not edit >>>
// PartInstanceLockedInPlace | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 575ce7ed | roc native-status --write
#undef _RELEASEASSERT
#include "v8datamodel/PartInstance.h"

namespace RBX {
bool PartInstance::lockedInPlace() const
{
    bool above = false, below = false;
    const Primitive* p = &primitive;
    Joint* joint = p->getFirstJoint();
    while (joint) {
        Edge* edge = joint;
        int type;
        if ((edge->getEdgeType() == Edge::JOINT &&
             ((type = joint->getJointType()) == Joint::WELD_JOINT || type == Joint::SNAP_JOINT)) ||
            (edge->getEdgeType() == Edge::JOINT && joint->getJointType() == Joint::MOTOR_JOINT)) {
            NormalId normal = p == edge->getPrimitive(0)
                ? Matrix3ToNormalId(joint->getJointCoord(0).rotation)
                : normalIdOpposite(Matrix3ToNormalId(joint->getJointCoord(1).rotation));
            if (normal == NORM_Y) above = true;
            else if (normal == NORM_Y_NEG) below = true;
        }
        joint = p->getNextJoint(joint);
    }
    return above && below;
}
}
