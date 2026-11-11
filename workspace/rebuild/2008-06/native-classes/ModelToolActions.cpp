// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// ModelToolActions | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src cc17d0a4 | roc native-status --write
#include "tool/ModelTools.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/PartInstance.h"
#include "util/Sound.h"

namespace RBX {
const std::string AnchorTool::getCursorName() const
{
    if (target) {
        if (anchored) return "UnAnchorCursor";
        return "AnchorCursor";
    }
    return "AnchorCursor";
}

const std::string LockTool::getCursorName() const
{
    if (target) {
        bool locked = PartInstance::getLocked(target.get());
        if (locked) return "UnlockCursor";
        return "LockCursor";
    }
    return "LockCursor";
}

MouseCommand* LockTool::onMouseDown(const UIEvent&)
{
    if (target) {
        bool value = PartInstance::getLocked(target.get());
        PartInstance::setLocked(target.get(), !value);
        ServiceProvider::create<Soundscape::SoundService>(workspace)->playSound(PING_SOUND);
    }
    return this;
}
}
