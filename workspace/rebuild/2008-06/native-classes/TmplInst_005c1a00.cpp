// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 005c1a00 ??$create@VBodyGyro@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VBodyGyro@RBX@@@boost@@XZ: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/BodyMovers.h"
#include "util/Object.h"

template boost::shared_ptr<RBX::BodyGyro> RBX::Creatable<RBX::Instance>::create<RBX::BodyGyro>();
