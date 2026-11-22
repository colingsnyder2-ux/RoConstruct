// native-flags: /O2 /GS- /EHsc /MD /fp:fast /I{headers}/partmaterial-profile /I{headers}/file-mesh-provider /I{headers}/part-embedded /I{headers}/partchunk-profile /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// 2008-06 native RBX::ViewNew::Part::getMaterial 004eb190 (inactive; Part vtable 00826f94 slot 5, 2849 bytes, ret 4,
// EH frame 007caa1c with a catch (const std::exception&) handler 004ebc46). Flags and include profile follow the
// sibling Decal / Texture::getMaterial unit native-classes/ViewNewSurfaceMaterial2008.cpp (004ebe70 / 004ec070 exact);
// /I{headers}/partmaterial-profile adds the MaterialFactory lookups 004f1a60 / 004f1c60.
// Shape: the byte-exact mining analog work/2008-06/p4-part-material.cpp (stub declarations) rewritten on the native
// declarations; control flow from the donor tools/openrbx Client/RbxView/Part.cpp Part::getMaterial plus the 2008
// clothing branch. Evidence (original call sites):
//   entry      the empty material 00972878 (a global RCP, no guard flag) is created once through 00551730 and given
//              one level: appendLevel (slot 3) with a NULL texture, Color3 white (00942904..0c) and four 0.0f.
//   attributes BrickColor PartInstance +0x1e4, alpha() (1 - (1 - [+0x1e8]) * [+0x328]), reflectance +0x1ec; colour
//              through BrickColor::color3 005b6270.
//   clothing   parent (+0x104) -> dynamic_cast<ModelInstance*> (00932a40) -> findModifierOfType<Clothing> 004e7ff0;
//              two ContentIds (ctor 0043d050) filled from each Clothing child (children +0x108, end 0068ff20 /
//              begin 0068fef0): the first from +0x134 (getOutfit1), the second from +0x154 (getOutfit2), operator=
//              0043d0a0; Humanoid::modelIsCharacter 005d9a20; the first content dresses getLeftLeg 005d8c10 /
//              getRightLeg 005d8d10 / getTorso 005d8b10, the second getLeftArm 005d8e10 / getRightArm 005d8f10 /
//              getTorso; ContentProvider (ServiceProvider 00465210) requestContentFile 00562670; the clothing image
//              helper 005ef840 (std::string by value, the mime Name, false, 1.0f); texture factory 00551920
//              (ViewBase +0xc textureManager, name, false); the texture's float property (slot 3) = 00826fd4.
//   fallback   usesMegaTexture 004e5f80 -> getMegaMaterial 004f1a60; FILE_MESH (+0x130 == 5) special shape ->
//              getTextureId 004e5f50 / getVertColor (+0x180) / getAlpha 0059eca0; otherwise getMaterial 004f1c60.
#undef OGRE_NONCLIENT_BUILD
#define NOMINMAX
#define NATIVE_HUMANOID2008_DONOR_CONNECTOR
#include <winsock2.h>
#include "util/NativeContentProvider.h"
#include "ViewNew/PartChunk.h"
#include "v8tree/Service.h"
#include "RenderLib/ViewBase2008.h"
#include "RenderLib/Material2008.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Clothing.h"
#include "v8datamodel/custommesh.h"
#include "humanoid/Humanoid2008.h"
#include "RbxGraphics/TextureProxyBase2008.h"
#include "util/StandardOut.h"
// INFERRED: descriptive helper/global names (same externs as ViewNewSurfaceMaterial2008.cpp), target calls
// 00551730 / 00551920 / 005ef840, the float 00826fd4 and the global RCP 00972878.
extern RBX::RenderBase::MaterialBase* createPartMaterial();
extern RBX::TextureProxyBase* createPartTexture(G3D::TextureManager*, const std::string&, bool);
extern std::string composeClothingTexture(std::string, const RBX::Name&, bool, float);
extern const float decalTextureScale;
extern G3D::ReferenceCountedPointer<RBX::RenderBase::MaterialBase> emptyPartMaterial;

namespace RBX { namespace ViewNew {

// 004eb190
G3D::ReferenceCountedPointer<RenderBase::MaterialBase> Part::getMaterial()
{
	if (emptyPartMaterial.isNull()) {
		emptyPartMaterial = createPartMaterial();
		emptyPartMaterial->appendLevel(TextureProxyBaseRef(), G3D::Color3::WHITE, 0, 0, 0, 0);
	}
	try {
		if (materialInvalid) {
			MaterialFactory::Attributes attributes = {partInstance->getColor(), partInstance->alpha(), partInstance->getReflectance()};
			G3D::Color3 color = partInstance->getColor().color3();
			std::string filename;
			Instance* parent = partInstance->getParent();
			{
				ModelInstance* model = NULL;
				if (parent) model = dynamic_cast<ModelInstance*>(parent);
				if (model && model->findModifierOfType<Clothing>()) {
				ContentId pants, shirt;
				if (parent->children) {
					std::vector<boost::shared_ptr<Instance> >::const_iterator end = parent->children->end();
					for (std::vector<boost::shared_ptr<Instance> >::const_iterator it = parent->children->begin(); it != end; ++it) {
						Clothing* clothing = dynamic_cast<Clothing*>((*it).get());
						if (clothing) {
							if (pants.isNull() && !clothing->getOutfit1().isNull())
								pants = clothing->getOutfit1();
							if (shirt.isNull() && !clothing->getOutfit2().isNull())
								shirt = clothing->getOutfit2();
						}
					}
				}
				if (!pants.isNull() || !shirt.isNull()) {
				Humanoid* humanoid = Humanoid::modelIsCharacter(parent);
				if (humanoid) {
				bool pantsPart = !pants.isNull() && (partInstance.get() == humanoid->getLeftLeg() || partInstance.get() == humanoid->getRightLeg() || partInstance.get() == humanoid->getTorso());
				bool shirtPart = !shirt.isNull() && (partInstance.get() == humanoid->getLeftArm() || partInstance.get() == humanoid->getRightArm() || partInstance.get() == humanoid->getTorso());
				ContentProvider::Status pantsStatus = ContentProvider::Succeeded, shirtStatus = ContentProvider::Succeeded;
				if (pantsPart || shirtPart) {
					material = NULL;
					if (pantsPart) {
						ServiceProvider::create<ContentProvider>(partInstance.get())->requestContentFile(pants, &pantsStatus, filename);
						if (pantsStatus == ContentProvider::Succeeded) {
							std::string composed = composeClothingTexture(filename, pants.mimeType(), false, 1.0f);
							material = createPartMaterial();
							material->appendLevel(TextureProxyBaseRef(NULL), color, 0.9f, 50.0f, partInstance->getReflectance(), partInstance->alpha());
							TextureProxyBase* texture = createPartTexture(view->textureManager.get(), composed, false);
							material->appendLevel(TextureProxyBaseRef(texture), G3D::Color3::WHITE, 0.9f, 50.0f, partInstance->getReflectance(), partInstance->alpha() + 0.001f);
							texture->setFloatProperty(decalTextureScale);
							if (shirt.isNull() || partInstance.get() != humanoid->getTorso())
								materialInvalid = false;
						}
					}
					if (shirtPart) {
						ServiceProvider::create<ContentProvider>(partInstance.get())->requestContentFile(shirt, &shirtStatus, filename);
						if (shirtStatus == ContentProvider::Succeeded) {
							do {
							std::string composed = composeClothingTexture(filename, shirt.mimeType(), false, 1.0f);
							if (humanoid->getTorso() == partInstance.get() && material.notNull() && material.notNull()) {
								TextureProxyBase* texture = createPartTexture(view->textureManager.get(), composed, false);
								material->appendLevel(TextureProxyBaseRef(texture), G3D::Color3::WHITE, 0.9f, 50.0f, partInstance->getReflectance(), partInstance->alpha() + 0.002f);
								texture->setFloatProperty(decalTextureScale);
do {} while (false);
							} else {
								material = createPartMaterial();
								material->appendLevel(TextureProxyBaseRef(), color, 0.9f, 50.0f, partInstance->getReflectance(), partInstance->alpha());
								TextureProxyBase* texture = createPartTexture(view->textureManager.get(), composed, false);
								material->appendLevel(TextureProxyBaseRef(texture), G3D::Color3::WHITE, 0.9f, 50.0f, partInstance->getReflectance(), partInstance->alpha() + 0.001f);
								texture->setFloatProperty(decalTextureScale);
							}
							materialInvalid = false;
							} while (false);
						}
					}
				}
				if (!materialInvalid)
					return material;
				if ((pantsPart && pantsStatus == 0) || (shirtPart && shirtStatus == 0)) {
					if (material != emptyPartMaterial)
						material = emptyPartMaterial.getPointer();
					return material;
				}
				}
				}
				}
			}
			if (usesMegaTexture())
				material = view->materialFactory->getMegaMaterial(attributes);
			else if (specialShape && specialShape->getMeshType() == SpecialShape::FILE_MESH) {
				std::string textureFile;
				bool failed;
				{
				ContentProvider::Status status;
				failed = (ServiceProvider::create<ContentProvider>(partInstance.get())->requestContentFile(specialShape->getTextureId(), &status, textureFile), status != ContentProvider::Succeeded);
				}
				if (failed) {
					material = view->materialFactory->getMaterial(attributes);
					return material;
				}
				G3D::Vector3 vertexColor = specialShape->getVertColor();
				float transparency = specialShape->getAlpha();
				material = createPartMaterial();
				material->appendLevel(TextureProxyBaseRef(createPartTexture(view->textureManager.get(), textureFile, false)), G3D::Color3(vertexColor), 0, 0.1f, 0, transparency);
				materialInvalid = false;
				goto done;
			} else
				material = view->materialFactory->getMaterial(attributes);
			materialInvalid = false;
			done: ;
		}
	} catch (const std::exception& error) {
		StandardOut::singleton()->print(MESSAGE_WARNING, error);
	}
	return material;
}

}}
