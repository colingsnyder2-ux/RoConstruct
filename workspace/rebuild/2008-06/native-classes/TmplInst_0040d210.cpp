// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0040d210 ??$create@VClasses@Metadata@Reflection@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VClasses@Metadata@Reflec: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "reflection/Metadata.h"
#include "util/Object.h"

template boost::shared_ptr<RBX::Reflection::Metadata::Classes> RBX::Creatable<RBX::Instance>::create<RBX::Reflection::Metadata::Classes>();
