// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// 005e4810: explicit instantiation of the class the body at 005e4810 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "v8datamodel/JointInstance.h"
#include "v8world/WeldJoint.h"
namespace RBX {
Weld::Weld(Joint* joint) : DescribedCreatable<Weld, JointInstance, sWeld>(joint) { setName(sWeld); }
}
namespace RBX {
Weld::Weld() : DescribedCreatable<Weld, JointInstance, sWeld>(new WeldJoint()) { setName(sWeld); }
}
