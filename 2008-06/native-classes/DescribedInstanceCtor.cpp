// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Reflection::Described<Instance, sInstance, DescribedBase>::Described() (inactive), the reflection.h template
// constructor emitted out of line. Flags line copied from the Instance sibling InstanceChildPermission.cpp.
// Identity: registry ??0?$Described@VInstance@RBX@@$1?sInstance@2@3QBDBVDescribedBase@Reflection@2@@Reflection@RBX@@QAE@XZ
// at 0055b780. Shape: the inline DescribedBase() (SignalSource +4 cleared, ClassDescriptor::lockedDown 00974c85 = 1,
// descriptor = &rootDescriptor() 0040ad20) and then descriptor = &classDescriptor() 0040ad80 at +8.
#include "v8tree/Instance.h"

// 0055b780
template RBX::Reflection::Described<RBX::Instance, RBX::sInstance, RBX::Reflection::DescribedBase>::Described();
