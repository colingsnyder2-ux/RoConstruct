// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "tool/ModelTools.h"
#include "StandardVerbs.h"

namespace RBX {
char sAnchorTool[] = "Anchor";
char sLockTool[] = "Lock";
template<> const Name& Named<ModelTool, sAnchorTool>::getName() const
{
    return NativeToolName<AnchorTool>::get();
}
template<> const Name& Named<ModelTool, sLockTool>::getName() const
{
    return NativeToolName<LockTool>::get();
}
}
