// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 005e3dd0: explicit instantiation of the class the body at 005e3dd0 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "util/Object.h"
#include "v8datamodel/JointInstance.h"
template class RBX::FactoryProduct<class RBX::Motor,class RBX::JointInstance,RBX::sMotor>;
namespace RBX { template RBX::FactoryProduct<class RBX::Motor,class RBX::JointInstance,RBX::sMotor>::FactoryProduct(Joint*); }
