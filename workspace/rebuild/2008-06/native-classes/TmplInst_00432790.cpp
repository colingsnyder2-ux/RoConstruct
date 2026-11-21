// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00432790 ??$create@VHat@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VHat@RBX@@@boost@@XZ: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/Accoutrement.h"
#include "util/Object.h"

template boost::shared_ptr<RBX::Hat> RBX::Creatable<RBX::Instance>::create<RBX::Hat>();
