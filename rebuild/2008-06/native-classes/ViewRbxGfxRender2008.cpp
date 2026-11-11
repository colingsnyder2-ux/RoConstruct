// native-flags: /O2 /GS- /EHsc /MD /fp:fast
// >>> native-status (generated) -- do not edit >>>
// ViewRbxGfxRender2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 7e29c93a | roc native-status --write
#include "RenderLib/ViewNew2008.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
void RBX::ViewNew::ViewRbxGfx::render(G3D::RenderDevice* rd)
{
    // INFERRED: Ogre context passes through the common render-device ABI.
    updateLighting(reinterpret_cast<Ogre::VisualEngine*>(rd));
    renderLibScene->render(rd, dataModel->getWorkspace()->getGCamera());
}
