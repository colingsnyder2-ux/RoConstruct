// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// GameTool | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 92ac86cd | roc native-status --write
#include "tool/BasicMouseTools.h"
#include "StandardVerbs.h"

namespace RBX {
char sGameTool[] = "GameTool";
GameTool::GameTool(Workspace* workspace) : Named<MouseCommand, sGameTool>(workspace) {}
GameTool::~GameTool() {}

template<> const Name& Named<MouseCommand, sGameTool>::getName() const
{
    return NativeToolName<GameTool>::get();
}
}
