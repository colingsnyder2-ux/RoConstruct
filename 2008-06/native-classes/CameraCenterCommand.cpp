// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// CameraCenterCommand | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by coldek (deepseek:deepseek-chat)
// <<< native-status | src 95053c5a | roc native-status --write
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Selection.h"
#include "StandardVerbs.h"
#include "util/Sound.h"
#include "NativeCameraCommands.h"

namespace RBX {
void CameraCenterCommand::doIt(IDataState* state) {
    ServiceClient<FilteredSelection<PVInstance> > selection(workspace);
    G3D::Vector3 center;
    if (selection->size() >= 1) {
        const std::vector<PVInstance*>& items = selection->items();
        Extents extents = items[0]->getExtentsWorld();
        for (size_t i = 1; i < items.size(); ++i) extents.unionWith(items[i]->getExtentsWorld());
        center = extents.center();
    } else center = G3D::Vector3::zero();
    workspace->getCamera()->setCameraType(Camera::FIXED_CAMERA);
    workspace->getCamera()->setCameraFocus(G3D::CoordinateFrame(center));
    ServiceProvider::create<Soundscape::SoundService>(static_cast<Instance*>(workspace))->playSound(STEP_SOUND);
    state->setDirty(true);
    state->setDirty(true);
}
}
