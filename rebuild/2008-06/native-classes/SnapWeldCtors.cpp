// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Snap/Weld constructors 005e4600, 005e4710 (Snap) and 005e4810, 005e44f0 (Weld): byte-exact. The DescribedCreatable base
// has no body of its own in 2008; the class name is set from the ctor (setName(sX)) after the vtable chain.
#include "v8datamodel/JointInstance.h"
#include "v8world/SnapJoint.h"
#include "v8world/WeldJoint.h"

namespace RBX {
Snap::Snap(Joint* joint) : DescribedCreatable<Snap, AutoJoint, sSnap>(joint) { setName(sSnap); }
Snap::Snap() : DescribedCreatable<Snap, AutoJoint, sSnap>(new SnapJoint()) { setName(sSnap); }
Weld::Weld(Joint* joint) : DescribedCreatable<Weld, AutoJoint, sWeld>(joint) { setName(sWeld); }
Weld::Weld() : DescribedCreatable<Weld, AutoJoint, sWeld>(new WeldJoint()) { setName(sWeld); }
}
