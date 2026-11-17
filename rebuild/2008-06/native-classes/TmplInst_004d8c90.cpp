// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 004d8c90 ??$create@VSky@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VSky@RBX@@@boost@@XZ: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/Sky.h"
#include "util/Object.h"

template boost::shared_ptr<RBX::Sky> RBX::Creatable<RBX::Instance>::create<RBX::Sky>();
