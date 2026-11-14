// Native integration entry. No fallback meshes, replacement Parts or stub providers.
// Kept out of the demo until its native dependency/ABI/runtime gates pass.
#undef OGRE_NONCLIENT_BUILD
#define NOMINMAX
#include <Ogre.h>
#include "OgreRbx/VisualEngine2008.h"
#include "RenderLib/ViewNew2008.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/PartInstance.h"
#include "util/SurfaceType.h"

__declspec(dllexport) void renderNativeParts(Ogre::VisualEngine& engine)
{
    boost::shared_ptr<RBX::DataModel> model=RBX::DataModel::createDataModel(false);
    {
        RBX::ViewNew::ViewRbxGfx view(model);
        view.sceneManager.reset(new RBX::RenderBase::AggregatingSceneManager(view.renderLibScene.get()));
        {
            RBX::DataModel::Lock lock(model);
            for(int i=0;i<8;++i) {
                boost::shared_ptr<RBX::PartInstance> part=RBX::Creatable<RBX::Instance>::create<RBX::PartInstance>();
                part->setName("StuddedBrick");
                part->setPartSizeXml(G3D::Vector3(8,2,8));
                part->setAnchored(true);
                part->getSurfaces()[RBX::NORM_Y].setSurfaceType(RBX::STUDS);
                part->setCoordinateFrame(G3D::CoordinateFrame(G3D::Vector3((i%4)*10,2,(i/4)*10)));
                part->setParent(model->getWorkspace());
            }
        }
        view.updateSettings(100,1,true,40);
        view.sceneManager->prerender(0.01);
        // The original ViewRbxGfx::render passes the VisualEngine context through
        // RenderDevice's interface to RenderNew::RenderScene (004daf10/007ab0a0).
        view.render(reinterpret_cast<G3D::RenderDevice*>(&engine));
    }
    RBX::DataModel::closeDataModel(model,false);
}
