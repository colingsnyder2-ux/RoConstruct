// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/camera-zoom
// >>> native-status (generated) -- do not edit >>>
// CameraZoomExtentsAction | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 4198072f | roc native-status --write
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Selection.h"
#include "StandardVerbs.h"
#include "util/Sound.h"
#include "NativeCameraCommands.h"

namespace RBX {
inline const Name& Verb::getName() const { return name; }
inline const G3D::Rect2D& RootInstance::getViewPort() { return viewPort; }
void recordCameraHistory(const char*, const Instance*);

void CameraZoomExtentsCommand::doIt(IDataState* state) {
    ServiceClient<FilteredSelection<PVInstance> > selection(workspace);
    Extents extents;
    if (selection->size() >= 1) {
        const std::vector<PVInstance*>& items = selection->items();
        extents = items[0]->getExtentsWorld();
        for (size_t i = 1; i < items.size(); ++i) extents.unionWith(items[i]->getExtentsWorld());
        workspace->getCamera()->setCameraType(Camera::FIXED_CAMERA);
        workspace->getCamera()->zoomExtents(extents, workspace->getViewPort(), Camera::ZOOM_IN_OR_OUT);
        ServiceProvider::create<Soundscape::SoundService>(static_cast<Instance*>(workspace))->playSound(STEP_SOUND);
        state->setDirty(true);
        recordCameraHistory(getName().c_str(), workspace);
        state->setDirty(true);
        return;
    }
    G3D::Vector3::zero();
    workspace->getCamera()->zoomExtents(workspace->getViewPort());
    ServiceProvider::create<Soundscape::SoundService>(static_cast<Instance*>(workspace))->playSound(STEP_SOUND);
    state->setDirty(true);
}
}
