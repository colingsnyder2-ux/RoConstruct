// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00490450 ??$create@VTeams@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VTeams@RBX@@@boost@@XZ: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/Teams.h"
#include "util/Object.h"

template boost::shared_ptr<RBX::Teams> RBX::Creatable<RBX::Instance>::create<RBX::Teams>();
