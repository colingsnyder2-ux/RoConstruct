// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::MouseCommand::ignoreVector3 (inactive): the private static G3D::Vector3 default argument of
// MouseCommand::getPart / getUnlockedPart (native-headers/v8datamodel/MouseCommand.h:30). No dynamic initializer
// exists for it in the exe (no ??__E in function-files.json), so it is zero data.
// INFERRED: zero initial value (default-constructed Vector3, no initializer function).
#include "v8datamodel/Workspace.h"
#include "v8datamodel/MouseCommand.h"

namespace RBX
{
	G3D::Vector3 MouseCommand::ignoreVector3;
}
