// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
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
