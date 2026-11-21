// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 005e41d0: explicit instantiation of the class the body at 005e41d0 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/reflection.h"
#include "v8datamodel/JointInstance.h"
template class RBX::DescribedCreatable<class RBX::RotateP,class RBX::JointInstance,RBX::sRotateP>;
namespace RBX { template RBX::DescribedCreatable<class RBX::RotateP,class RBX::JointInstance,RBX::sRotateP>::DescribedCreatable(Joint*); }
