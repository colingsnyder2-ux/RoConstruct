// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 00801680: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "util/Name.h"
#include "v8datamodel/JointInstance.h"

namespace RBX {

template void Name::callDoDeclare<sMotor>();

}
