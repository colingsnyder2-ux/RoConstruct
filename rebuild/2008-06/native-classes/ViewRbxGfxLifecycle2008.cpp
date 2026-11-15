// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/viewrbx-ctor-profile /I{headers}/partchunk-profile /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Original 004db4f0 (destructor). suppressSkybox 004d9c90 is defined (exact) in RenderSceneViewRbxGfx2008.cpp.
#include "RenderLib/ViewNew2008.h"
#include "RenderLib/RenderSceneNew2008.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Lighting2008.h"
#include "ViewNew/CylinderMesh.h"
#include "ViewNew/SphereMesh.h"
#include "ViewNew/PBBMesh.h"
#include "ViewNew/BrickMesh.h"
#include "ViewNew/WedgeMesh.h"
#include "ViewNew/HeadMesh.h"
#include "ViewNew/TorsoMesh.h"
namespace RBX { namespace ViewNew {
ViewRbxGfx::~ViewRbxGfx()
{
    sceneManager->clear();
    renderLibScene.reset();
    materialFactory.reset();
    textureManager.reset();
    ServiceProvider::create<Lighting>(dataModel.get());
    CylinderAlongXMesh::flushCache();
    SphereMesh::flushCache();
    PBBMesh::flushCache();
    BrickMesh::flushCache();
    WedgeMesh::flushCache();
    HeadMesh::flushCache();
    TorsoMesh::flushCache();
}
} }
