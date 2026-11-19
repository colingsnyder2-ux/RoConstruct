// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 004901e0 ??$create@VSkin@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VSkin@RBX@@@boost@@XZ: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/Clothing.h"
#include "util/Object.h"

template boost::shared_ptr<RBX::Skin> RBX::Creatable<RBX::Instance>::create<RBX::Skin>();
