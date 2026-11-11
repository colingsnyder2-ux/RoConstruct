// native-flags: /O2 /GS- /EHsc /MD /fp:fast /Ob1
// 2008-06 native RBX::ViewNew::Part / PartChunk bodies that need the complete PartInstance (inactive): cframe,
// ~Part, Part's invalidate slot and the Decal / Texture property handlers (Texture's 004e6bc0 is a block-order
// near-miss: recorded, not counted). Bodies that read PartInstance fields (+0x1c8 / +0x1dc / +0x224) or the view's
// scene manager are not built; see native-headers/ViewNew/PartChunk.h.
// >>> native-status (generated) -- do not edit >>>
// ViewNewPart | 2008-06 | 3 byte-exact, inactive (not link-selected)
// 3/8 mapped addresses byte-exact | 5 unproved | no mapped strings | by king_originala (+3) (mixed 3)
// <<< native-status | src e8aa6d57 | roc native-status --write
#include "ViewNew/PartChunk.h"
#include "RenderLib/ViewBase2008.h"
#include "v8datamodel/PartInstance.h"
// Native v8datamodel/Decal.h: the 2008 class names are char arrays (RTTI $1?sDecal@2@3PADA / $1?sTexture@2@3PADA).
#include "v8datamodel/Decal.h"
#include "v8datamodel/Clothing.h"
#include "humanoid/Humanoid.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/custommesh.h"

namespace RBX
{
	namespace ViewNew
	{
		const G3D::CoordinateFrame& PartChunk::cframe()
		{
			coordinateFrame = partInstance->getCoordinateFrame();
			return coordinateFrame;
		}

		Part::~Part()
		{
			if (partInstance)
				partInstance->Notifier<PartInstance, CanAggregateChanged>::removeListener(this);
		}

		// PartInstance::prop_Color 0097610c, prop_Transparency 00976128 ("Transparency"), prop_Reflectance 0097601c
		// ("Reflectance"): the descriptor names come from their initializers 007f46f0 / 007f4750.
		void Part::onPropertyChanged(const Reflection::PropertyDescriptor* descriptor)
		{
			PartChunk::onPropertyChanged(descriptor);

			if (*descriptor == PartInstance::prop_Color)
			{
				if (usesMegaTexture())
					invalidateMesh();
				invalidateMaterial();
			}
			else if (*descriptor == PartInstance::prop_Transparency || *descriptor == PartInstance::prop_Reflectance)
			{
				invalidateMaterial();
			}
		}

		void Part::invalidate()
		{
			invalidateMaterial();
			invalidateMesh();
		}

		bool Part::usesMegaTexture() const
		{
			if (specialShape == NULL && partInstance->getPartType() == RBX::Part::BLOCK_PART)
			{
				G3D::Vector3 size = partInstance->getPartSizeXml();
				float x = fabs(size.x);
				float y = fabs(size.y);
				float z = fabs(size.z);
				float m = x > y ? x : y;
				return (z < m ? m : z) < 30.0f;
			}
			return false;
		}

		void Part::onEvent(const PartInstance* source, CanAggregateChanged event)
		{
			{
				G3D::ReferenceCountedPointer<RenderBase::Chunk> chunk(this);
				view->sceneManager->setSleeping(chunk, event.canClump);
			}
			if (!event.canClump)
			{
				if (getSortValue() < 0.5f)
					setSortValue(0.5f);
			}
			else
			{
				if (getSortValue() < 1.0f)
					setSortValue(0.0f);
			}
		}

		// FaceInstance::prop_Face 0097b57c ("Face"), Decal::prop_Texture 00975f14 / prop_Specular 00975ef8 /
		// prop_Shiny 00975f30, Texture::prop_StudsPerTileU 00975f68 / prop_StudsPerTileV 00975f4c (initializers
		// 007f7600 and 007f4190..007f4290 name them).
		void Decal::onDecalPropertyChanged(const Reflection::PropertyDescriptor* descriptor)
		{
			if (*descriptor == FaceInstance::prop_Face)
				invalidateMesh();
			else if (*descriptor == RBX::Decal::prop_Texture || *descriptor == RBX::Decal::prop_Specular || *descriptor == RBX::Decal::prop_Shiny)
				invalidateMaterial();
		}

		void Texture::onTexturePropertyChanged(const Reflection::PropertyDescriptor* descriptor)
		{
			if (*descriptor == FaceInstance::prop_Face)
				invalidateMesh();
			else if (*descriptor == RBX::Decal::prop_Texture || *descriptor == RBX::Decal::prop_Specular || *descriptor == RBX::Decal::prop_Shiny)
				invalidateMaterial();
			else if (*descriptor == RBX::Texture::prop_StudsPerTileU || *descriptor == RBX::Texture::prop_StudsPerTileV)
				invalidateMesh();
		}
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::Listener<RBX::PartInstance,RBX::CanAggregateChanged>;
template class std::_Vector_const_iterator<RBX::Listener<RBX::PartInstance,RBX::CanAggregateChanged> *,std::allocator<RBX::Listener<RBX::PartInstance,RBX::CanAggregateChanged> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::PartInstance,RBX::CanAggregateChanged> *,std::allocator<RBX::Listener<RBX::PartInstance,RBX::CanAggregateChanged> *> >;

// 004eb190: transplanted from the server-exact analog (analog_to_native --transplant)
namespace RBX {
namespace ViewNew {
PartMaterialRef Part::getMaterial() {
    if (emptyMaterial.isNull()) {
        emptyMaterial = createPartMaterial();
        emptyMaterial->appendLevel(TextureProxyBaseRef(), G3D::Color3::WHITE, 0, 0, 0, 0);
    }
    try {
        if (materialInvalid) {
            PartMaterialFactory::Attributes attributes = {partInstance->getColor(), partInstance->alpha(), partInstance->getReflectance()};
            G3D::Color3 color = partInstance->getColor().color3();
            std::string filename;
            Instance* parent = partInstance->getParent();
            {
                ModelInstance* model = NULL;
                if (parent) model = dynamic_cast<ModelInstance*>(parent);
                if (model && model->findModifier()) {
                ContentId shirt, pants;
                if (parent->getChildren()) {
                    Instances::const_iterator end = parent->getChildren()->end();
                    for (Instances::const_iterator it = parent->getChildren()->begin(); it != end; ++it) {
                        Clothing* clothing = dynamic_cast<Clothing*>((*it).get());
                        if (clothing) {
                            if (shirt.isNull() && !clothing->shirtTemplate.isNull())
                                shirt = clothing->shirtTemplate;
                            if (pants.isNull() && !clothing->pantsTemplate.isNull())
                                pants = clothing->pantsTemplate;
                        }
                    }
                }
                if (!shirt.isNull() || !pants.isNull()) {
                Humanoid* humanoid = Humanoid::modelIsCharacter(parent);
                if (humanoid) {
                bool shirtPart = !shirt.isNull() && (partInstance.get() == humanoid->getLeftArm() || partInstance.get() == humanoid->getRightArm() || partInstance.get() == humanoid->getTorso());
                bool pantsPart = !pants.isNull() && (partInstance.get() == humanoid->getLeftLeg() || partInstance.get() == humanoid->getRightLeg() || partInstance.get() == humanoid->getTorso());
                int shirtStatus = 1, pantsStatus = 1;
                if (shirtPart || pantsPart) {
                    material = NULL;
                    if (shirtPart) {
                        ServiceProvider::find<ContentProvider>(partInstance.get())->requestContentFile(shirt, &shirtStatus, filename);
                        if (shirtStatus == 1) {
                            std::string migrated = migrateAtlas(filename, shirt.mimeType(), false, 1.0f);
                            material = createPartMaterial();
                            material->appendLevel(TextureProxyBaseRef(NULL), color, 0.9f, 50.0f, partInstance->getReflectance(), partInstance->alpha());
                            TextureProxyBase* texture = createPartTexture(view->getDevice(), migrated, false);
                            material->appendLevel(TextureProxyBaseRef(texture), G3D::Color3::WHITE, 0.9f, 50.0f, partInstance->getReflectance(), partInstance->alpha() + 0.001f);
                            texture->setFloat2c(decalTextureScale);
                            if (pants.isNull() || partInstance.get() != humanoid->getTorso())
                                materialInvalid = false;
                        }
                    }
                    if (pantsPart) {
                        ServiceProvider::find<ContentProvider>(partInstance.get())->requestContentFile(pants, &pantsStatus, filename);
                        if (pantsStatus == 1) {
                            do {
                            std::string migrated = migrateAtlas(filename, pants.mimeType(), false, 1.0f);
                            if (humanoid->getTorso() == partInstance.get() && material.notNull() && material.notNull()) {
                                TextureProxyBase* texture = createPartTexture(view->getDevice(), migrated, false);
                                material->appendLevel(TextureProxyBaseRef(texture), G3D::Color3::WHITE, 0.9f, 50.0f, partInstance->getReflectance(), partInstance->alpha() + 0.002f);
                                texture->setFloat2c(decalTextureScale);
do {} while (false);
                            } else {
                                material = createPartMaterial();
                                material->appendLevel(TextureProxyBaseRef(), color, 0.9f, 50.0f, partInstance->getReflectance(), partInstance->alpha());
                                TextureProxyBase* texture = createPartTexture(view->getDevice(), migrated, false);
                                material->appendLevel(TextureProxyBaseRef(texture), G3D::Color3::WHITE, 0.9f, 50.0f, partInstance->getReflectance(), partInstance->alpha() + 0.001f);
                                texture->setFloat2c(decalTextureScale);
                            }
                            materialInvalid = false;
                            } while (false);
                        }
                    }
                }
                if (!materialInvalid)
                    return material;
                if ((shirtPart && shirtStatus == 0) || (pantsPart && pantsStatus == 0)) {
                    if (material != emptyMaterial)
                        material = emptyMaterial.getPointer();
                    return material;
                }
                }
                }
                }
            }
            if (usesMegaTexture())
                material = view->getMaterialFactory()->getMegaMaterial(attributes);
            else if (specialShape && specialShape->getMeshType() == 5) {
                std::string textureFile;
                bool failed;
                {
                int status;
                failed = (ServiceProvider::find<ContentProvider>(partInstance.get())->requestContentFile(specialShape->getTextureId(), &status, textureFile), status != 1);
                }
                if (failed) {
                    material = view->getMaterialFactory()->getMaterial(attributes);
                    return material;
                }
                G3D::Vector3 vertexColor = specialShape->getVertexColor();
                float transparency = specialShape->getAlpha();
                material = createPartMaterial();
                material->appendLevel(TextureProxyBaseRef(createPartTexture(view->getDevice(), textureFile, false)), G3D::Color3(vertexColor), 0, 0.1f, 0, transparency);
                materialInvalid = false;
                goto done;
            } else
                material = view->getMaterialFactory()->getMaterial(attributes);
            materialInvalid = false;
            done: ;
        }
    } catch (const std::exception& error) {
        StandardOut::singleton()->print(MESSAGE_WARNING, error);
    }
    return material;
}
}
}
