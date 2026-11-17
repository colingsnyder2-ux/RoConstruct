// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0045c580 ??$create@VControllerService@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VControllerService@RBX@@@boost@@XZ: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/UserController.h"
#include "util/Object.h"

template boost::shared_ptr<RBX::ControllerService> RBX::Creatable<RBX::Instance>::create<RBX::ControllerService>();
