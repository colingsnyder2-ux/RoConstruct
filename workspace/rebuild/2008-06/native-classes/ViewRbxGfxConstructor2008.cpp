// INFERRED: constructor identity from unique exact candidate, RTTI vtable and original caller.
// native-flags: /O2 /GS- /EHsc /MD /I{headers}/viewrbx-ctor-profile /I{headers}/partchunk-profile /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// ViewRbxGfxConstructor2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 4ae9e76b | roc native-status --write
#undef OGRE_NONCLIENT_BUILD
#define NOMINMAX
#include "RenderLib/ViewNew2008.h"
#include "RenderLib/RenderSceneNew2008.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Lighting2008.h"
#include "v8tree/Service.h"
#include <boost/bind.hpp>
namespace RBX { namespace ViewNew {
ViewRbxGfx::ViewRbxGfx(boost::shared_ptr<DataModel> dm) : ViewBase(dm), skyValid(false) {
 renderLibScene.reset(new RenderNew::RenderScene);
 textureManager.reset(new G3D::TextureManager(0xa00000));
 sceneManager.reset(new RenderBase::SimpleSceneManager(renderLibScene.get()));
 materialFactory.reset(new MaterialFactory(textureManager.get()));
 renderLibScene->setThrottle(0.f,0.f,false,0.f);
 Lighting* lighting = ServiceProvider::find<Lighting>(dm.get());
 lightingChangedConnection = Lighting::event_LightingChanged.connect(lighting, boost::bind(&ViewRbxGfx::invalidateLighting,this,_1),10);
 dm->getWorkspace()->visitDescendents(boost::bind(&ViewRbxGfx::onWorkspaceDescendentAdded,this,_1));
 workspaceDescendentAddedConnection = Instance::event_descendentAdded.connect(dm->getWorkspace(), boost::bind(&ViewRbxGfx::onWorkspaceDescendentAdded,this,_1),10);
}
}}

// INFERRED: original relocations 0055d0b0 / 00551920 / 00551a30; descriptive names only.
extern std::string makeAssetPath(const char*);
extern RBX::TextureProxyBase* createPartTexture(G3D::TextureManager*, const std::string&, bool);
extern RBX::TextureProxyBase* createStripTexture(G3D::TextureManager*, const std::string&);
namespace RBX { namespace ViewNew {
MaterialFactory::MaterialFactory(G3D::TextureManager* textureManager) {
 surfacesTexture = createPartTexture(textureManager, makeAssetPath("textures\\surfaces.png"), true);
 fileMeshTexture = createPartTexture(textureManager, makeAssetPath("textures\\JohnTex.png"), false);
 megaTexture = createStripTexture(textureManager, makeAssetPath("textures\\SurfacesStrip.png"));
}
}}
