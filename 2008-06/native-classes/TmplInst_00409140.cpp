// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00409140 ??$create@VTeam@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VTeam@RBX@@@boost@@XZ: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/Team.h"
#include "util/Object.h"

template boost::shared_ptr<RBX::Team> RBX::Creatable<RBX::Instance>::create<RBX::Team>();
