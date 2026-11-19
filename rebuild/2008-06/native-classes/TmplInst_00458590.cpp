// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00458590 ??$create@VProperties@Metadata@Reflection@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VProperties@Metadata@: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "reflection/Metadata.h"
#include "util/Object.h"

template boost::shared_ptr<RBX::Reflection::Metadata::Properties> RBX::Creatable<RBX::Instance>::create<RBX::Reflection::Metadata::Properties>();
