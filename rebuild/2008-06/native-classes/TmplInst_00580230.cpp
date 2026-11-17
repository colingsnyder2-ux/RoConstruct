// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00580230 ??$create@VHole@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VHole@RBX@@@boost@@XZ: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/Feature.h"
#include "util/Object.h"

template boost::shared_ptr<RBX::Hole> RBX::Creatable<RBX::Instance>::create<RBX::Hole>();
