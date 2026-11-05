// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_8bf60529a275bcc6.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/ReferenceCount.h>
#include <G3D/Color3.h>
#include <G3D/Vector3.h>
#include <v8datamodel/BrickColor.h>
#include <util/Name.h>
#include <util/StandardOut.h>
#include <boost/shared_ptr.hpp>
#include <vector>
#include <string>
#include <exception>

namespace RBX {
class ContentId {
    std::string id;
    const Name* mimeTypePtr;
public:
    ContentId();
    ContentId& operator=(const ContentId&);
    bool isNull() const {return id.empty();}
    const Name& mimeType() const {return *mimeTypePtr;}
};
class TextureId : public ContentId {};
class Instance;
typedef std::vector<boost::shared_ptr<Instance> > Instances;
class Instance {
public:
    virtual ~Instance();
    char ipad[0x100];
    Instance* parent;
    const Instances* children;
    Instance* getParent() const { return parent; }
    const Instances* getChildren() const { return children; }
};
class ModelInstance : public Instance {
public:
    void* findModifier();
};
class Clothing : public Instance {
public:
    char cpad[0x134 - sizeof(Instance)];
    ContentId shirtTemplate;
    ContentId pantsTemplate;
};
class PartInstance : public Instance {
public:
    char ppad[0x1e4 - sizeof(Instance)];
    BrickColor color;
    float transparencyModifier;
    float reflectance;
    char ppad2[0x328 - 0x1f0];
    float transparency;
    BrickColor getColor() const { return color; }
    float getReflectance() const { return reflectance; }
    float alpha() const { return 1.0f - (1.0f - transparencyModifier) * transparency; }
};
class Humanoid {
public:
    static Humanoid* modelIsCharacter(Instance*);
    PartInstance* getLeftArm() const;
    PartInstance* getRightArm() const;
    PartInstance* getTorso() const;
    PartInstance* getLeftLeg() const;
    PartInstance* getRightLeg() const;
};
class ContentProvider {
public:
    void requestContentFile(const ContentId&, int*, std::string&);
};
class ServiceProvider {
public:
    template<class T> static T* find(const Instance*);
};
template<> ContentProvider* ServiceProvider::find<ContentProvider>(const Instance*);
class SpecialShape : public Instance {
public:
    char spad[0x130 - sizeof(Instance)];
    int meshType;
    char spad2[0x180 - 0x134];
    G3D::Vector3 vertexColor;
    int getMeshType() const { return meshType; }
    TextureId getTextureId() const;
    float getAlpha() const;
    const G3D::Vector3& getVertexColor() const { return vertexColor; }
};
class TextureProxyBase : public G3D::ReferenceCountedObject {
public:
    virtual ~TextureProxyBase();
    virtual void setValue28(unsigned);
    virtual unsigned getValue28() const;
    virtual void setFloat2c(float);
    virtual float getFloat2c() const;
};
typedef G3D::ReferenceCountedPointer<TextureProxyBase> TextureProxyBaseRef;
namespace RenderBase {
class MaterialBase : public G3D::ReferenceCountedObject {
public:
    class Level {
    public:
        virtual bool isEmptyLevel() const;
        virtual ~Level();
    };
    virtual ~MaterialBase();
    virtual const Level& appendEmptyLevel();
    virtual const Level& appendLevel(TextureProxyBaseRef,G3D::Color3,float,float,float,float);
    virtual const Level& appendLevel(G3D::Color3,float,float,float,float);
};
class Mesh : public G3D::ReferenceCountedObject {};
}
typedef G3D::ReferenceCountedPointer<RenderBase::MaterialBase> PartMaterialRef;
}
namespace RBX {
}
namespace RBX {
class PartMaterialFactory {
public:
    struct Attributes {
        BrickColor color;
        float transparency;
        float reflectance;
    };
    PartMaterialRef getMegaMaterial(Attributes);
    PartMaterialRef getMaterial(Attributes);
};
namespace ViewNew {
class View { char pad[0xc]; void* device; PartMaterialFactory* factory;
public:
    void* getDevice() const { return device; }
    PartMaterialFactory* getMaterialFactory() const { return factory; }
};
class PartChunk {
protected:
    virtual ~PartChunk();
    char pad[0xb8];
    boost::shared_ptr<PartInstance> partInstance;
    PartMaterialRef material;
    bool materialInvalid;
    G3D::ReferenceCountedPointer<RenderBase::Mesh> mesh;
    View* view;
    SpecialShape* specialShape;
};
}
}
extern RBX::RenderBase::MaterialBase* createPartMaterial();
extern RBX::TextureProxyBase* createPartTexture(void*,const std::string&,bool);
extern std::string migrateAtlas(std::string,const RBX::Name&,bool,float);
extern const float decalTextureScale;
extern RBX::PartMaterialRef emptyMaterial;

namespace RBX { namespace ViewNew {
class Part : public PartChunk {
public:
    PartMaterialRef getMaterial();
    bool usesMegaTexture() const;
    
};


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

}}
