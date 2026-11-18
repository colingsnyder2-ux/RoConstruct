// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 005e4100: explicit instantiation of the class the body at 005e4100 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/reflection.h"
#include "v8datamodel/JointInstance.h"
template class RBX::DescribedCreatable<class RBX::Rotate,class RBX::JointInstance,RBX::sRotate>;
namespace RBX { template RBX::DescribedCreatable<class RBX::Rotate,class RBX::JointInstance,RBX::sRotate>::DescribedCreatable(Joint*); }
