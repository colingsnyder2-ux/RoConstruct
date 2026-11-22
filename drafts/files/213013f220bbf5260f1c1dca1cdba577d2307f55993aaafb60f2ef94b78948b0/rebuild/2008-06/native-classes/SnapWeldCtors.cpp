// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Snap/Weld constructors 005e4600, 005e4710 (Snap) and 005e4810, 005e44f0 (Weld): byte-exact. The DescribedCreatable base
// has no body of its own in 2008; the class name is set from the ctor (setName(sX)) after the vtable chain.
#include "v8datamodel/JointInstance.h"
#include "v8world/SnapJoint.h"
#include "v8world/WeldJoint.h"

namespace RBX {
// Template base follows the JointInstance.h declaration (binary RTTI binds DescribedCreatable<Snap, JointInstance, sSnap>).
Snap::Snap(Joint* joint) : DescribedCreatable<Snap, JointInstance, sSnap>(joint) { setName(sSnap); }  // 005e44f0
Snap::Snap() : DescribedCreatable<Snap, JointInstance, sSnap>(new SnapJoint()) { setName(sSnap); }    // 005e4600
Weld::Weld(Joint* joint) : DescribedCreatable<Weld, JointInstance, sWeld>(joint) { setName(sWeld); }  // 005e4710
Weld::Weld() : DescribedCreatable<Weld, JointInstance, sWeld>(new WeldJoint()) { setName(sWeld); }    // 005e4810
}
