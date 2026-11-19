// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0041cda0 ??$create@VFunctions@Metadata@Reflection@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VFunctions@Metadata@Re: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "reflection/Metadata.h"
#include "util/Object.h"

template boost::shared_ptr<RBX::Reflection::Metadata::Functions> RBX::Creatable<RBX::Instance>::create<RBX::Reflection::Metadata::Functions>();
