// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../native-classes
// 004ac350: forwarding thunk generated from its proven jump target (thunk_lane.py, no model)
#include "v8datamodel/JointInstance.h"
// INFERRED: sRotate is declared in v8datamodel/JointInstance.h and defined nowhere in the native tree; its value is read from the image.
namespace RBX { const char sRotate[] = "Rotate"; }
template void RBX::Name::callDoDeclare<RBX::sRotate>();
