// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0041ec30 ??$create@VSpecialShape@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VSpecialShape@RBX@@@boost@@XZ: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/SpecialShape.h"
#include "util/Object.h"

template boost::shared_ptr<RBX::SpecialShape> RBX::Creatable<RBX::Instance>::create<RBX::SpecialShape>();
