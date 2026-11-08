// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/MouseCommand.h"
#include "v8datamodel/Filters.h"
#include "v8datamodel/Workspace.h"

namespace RBX {
UnlockedPartByLocalCharacter::UnlockedPartByLocalCharacter(Instance* root)
    : PartByLocalCharacter(root) {}

PartInstance* MouseCommand::getUnlockedPartByLocalCharacter(const UIEvent& event, G3D::Vector3& hitWorld)
{
    UnlockedPartByLocalCharacter filter(workspace);
    return getPart(event, &filter, hitWorld);
}
}
