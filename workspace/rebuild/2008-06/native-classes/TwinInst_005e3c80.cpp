// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 005e3c80: explicit instantiation of the class the body at 005e3c80 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "util/Object.h"
#include "v8datamodel/JointInstance.h"
template class RBX::FactoryProduct<class RBX::Rotate,class RBX::JointInstance,RBX::sRotate>;
namespace RBX { template RBX::FactoryProduct<class RBX::Rotate,class RBX::JointInstance,RBX::sRotate>::FactoryProduct(Joint*); }
