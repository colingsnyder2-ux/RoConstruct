// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "tool/SurfaceTool.h"
#include "v8datamodel/Workspace.h"
#include "util/Sound.h"

namespace RBX {
void recordCameraHistory(const char*, const Instance*);

MouseCommand* SurfaceTool::onMouseDown(const UIEvent& input)
{
    onMouseHover(input);
    if (surface) {
        applyToSurface(surface);
        ServiceProvider::create<Soundscape::SoundService>(static_cast<Instance*>(workspace))->playSound(PING_SOUND);
        recordCameraHistory(cursor.c_str(), static_cast<Instance*>(workspace));
        workspace->getDataState().setDirty(true);
    }
    return NULL;
}
}
