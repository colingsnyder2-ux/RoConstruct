// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 005c3da0 ??$create@VObjectValue@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VObjectValue@RBX@@@boost@@XZ: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/Value.h"
#include "util/Object.h"

template boost::shared_ptr<RBX::ObjectValue> RBX::Creatable<RBX::Instance>::create<RBX::ObjectValue>();
