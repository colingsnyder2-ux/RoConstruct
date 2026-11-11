// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// MouseUnlocked | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 9d05bb7a | roc native-status --write
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
