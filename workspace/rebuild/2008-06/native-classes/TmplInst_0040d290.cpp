// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0040d290 ??$create@VDHTMLWindowService@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VDHTMLWindowService@@@boost@@XZ: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "AppLeaves2008/DHTMLWindowService2008.h"
#include "util/Object.h"

template boost::shared_ptr<DHTMLWindowService> RBX::Creatable<RBX::Instance>::create<DHTMLWindowService>();
