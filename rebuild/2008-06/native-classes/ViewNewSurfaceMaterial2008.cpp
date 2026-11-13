// native-flags: /O2 /GS- /EHsc /MD /fp:fast /I{headers}/file-mesh-provider /I{headers}/part-embedded /I{headers}/partchunk-profile /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// ViewNewSurfaceMaterial2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 98c4c064 | roc native-status --write
#undef OGRE_NONCLIENT_BUILD
#define NOMINMAX
#include <winsock2.h>
#include "util/NativeContentProvider.h"
#include "ViewNew/PartChunk.h"
#include "v8tree/Service.h"
#include "RenderLib/ViewBase2008.h"
#include "RenderLib/Material2008.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Decal.h"
#include "RbxGraphics/TextureProxyBase2008.h"
// INFERRED: descriptive helper/global names, target calls 00551730/00551920 and float relocation.
extern RBX::RenderBase::MaterialBase* createPartMaterial();
extern RBX::TextureProxyBase* createPartTexture(G3D::TextureManager*, const std::string&, bool);
extern const float decalTextureScale;
namespace RBX { namespace ViewNew {
G3D::ReferenceCountedPointer<RenderBase::MaterialBase> Decal::getMaterial() {
 ContentProvider::Status status;
 try {
  if (materialInvalid && partInstance) {
   std::string filename;
   ServiceProvider::find<ContentProvider>(partInstance.get())->requestContentFile(decal->getTexture(), &status, filename);
   if (status == 1) {
    material = createPartMaterial();
    TextureProxyBase* texture = createPartTexture(view->textureManager.get(), filename, false);
    // INFERRED: original loads PartInstance +0x328; semantic field name unconfirmed.
    float transparency = partInstance->getAlphaModifier();
    material->appendLevel(TextureProxyBaseRef(texture), G3D::Color3::WHITE,
     decal->getSpecular(), decal->getShiny(), 0.0f, 1.0f - transparency);
    texture->setFloatProperty(decalTextureScale);
    materialInvalid = false;
   } else if (status == 2) {
    material = NULL;
    materialInvalid = false;
   }
  }
 } catch (...) {}
 return material;
}
G3D::ReferenceCountedPointer<RenderBase::MaterialBase> Texture::getMaterial() {
 ContentProvider::Status status;
 try {
  if (materialInvalid) {
   std::string filename;
   if ((ServiceProvider::find<ContentProvider>(partInstance.get())->requestContentFile(decal->getTexture(), &status, filename), status == 1)) {
    material = createPartMaterial();
    TextureProxyBase* texture = createPartTexture(view->textureManager.get(), filename, true);
    // INFERRED: original loads PartInstance +0x328; semantic field name unconfirmed.
    float transparency = partInstance->getAlphaModifier();
    material->appendLevel(TextureProxyBaseRef(texture), G3D::Color3::WHITE,
     decal->getSpecular(), decal->getShiny(), 0.0f, 1.0f - transparency);
    texture->setFloatProperty(decalTextureScale);
    materialInvalid = false;
   }
  }
 } catch (...) {}
 return material;
}

}}
