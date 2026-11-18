// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 005e4010: explicit instantiation of the class the body at 005e4010 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "reflection/reflection.h"
#include "v8datamodel/JointInstance.h"
template class RBX::DescribedCreatable<class RBX::Glue,class RBX::JointInstance,RBX::sGlue>;
namespace RBX { template RBX::DescribedCreatable<class RBX::Glue,class RBX::JointInstance,RBX::sGlue>::DescribedCreatable(Joint*); }
