#include "v8datamodel/JointInstance.h"
#include "v8world/SnapJoint.h"
#include "v8world/WeldJoint.h"

namespace RBX {
Snap::Snap(Joint* joint) : DescribedCreatable<Snap, AutoJoint, sSnap>(joint) { setName(sSnap); }
Snap::Snap() : DescribedCreatable<Snap, AutoJoint, sSnap>(new SnapJoint()) { setName(sSnap); }
Weld::Weld(Joint* joint) : DescribedCreatable<Weld, AutoJoint, sWeld>(joint) { setName(sWeld); }
Weld::Weld() : DescribedCreatable<Weld, AutoJoint, sWeld>(new WeldJoint()) { setName(sWeld); }
}
