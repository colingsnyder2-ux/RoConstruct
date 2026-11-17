// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00414bd0 ??$create@VScript@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VScript@RBX@@@boost@@XZ: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "script/Script.h"
#include "util/Object.h"

template boost::shared_ptr<RBX::Script> RBX::Creatable<RBX::Instance>::create<RBX::Script>();
