// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00432520 ??$create@VAccoutrement@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VAccoutrement@RBX@@@boost@@XZ: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/Accoutrement.h"
#include "util/Object.h"

template boost::shared_ptr<RBX::Accoutrement> RBX::Creatable<RBX::Instance>::create<RBX::Accoutrement>();
