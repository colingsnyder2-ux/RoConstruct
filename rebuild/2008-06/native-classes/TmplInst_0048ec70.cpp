// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0048ec70 ??$create@VLegacyHopperService@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VLegacyHopperService@RBX@@@boost: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/Hopper.h"
#include "util/Object.h"

template boost::shared_ptr<RBX::LegacyHopperService> RBX::Creatable<RBX::Instance>::create<RBX::LegacyHopperService>();
