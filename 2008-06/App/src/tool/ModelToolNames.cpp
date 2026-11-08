// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// ModelToolNames | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src dfbf8211 | roc native-status --write
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
