// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 005e3e60: explicit instantiation of the class the body at 005e3e60 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/reflection.h"
#include "v8datamodel/JointInstance.h"
template class RBX::DescribedCreatable<class RBX::Snap,class RBX::JointInstance,RBX::sSnap>;
namespace RBX { template RBX::DescribedCreatable<class RBX::Snap,class RBX::JointInstance,RBX::sSnap>::DescribedCreatable(Joint*); }
