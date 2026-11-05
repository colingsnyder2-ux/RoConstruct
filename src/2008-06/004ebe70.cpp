// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_f5049ed04078a64d.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/ReferenceCount.h>
#include <G3D/Color3.h>
#include <util/Name.h>
#include <string>
#include <boost/shared_ptr.hpp>

namespace RBX {
class ContentId {
    std::string id;
    const Name* mimeTypePtr;
public:
    ContentId();
};
class TextureId : public ContentId {};
class Instance { public: virtual ~Instance(); };
class PartInstance : public Instance {
    char pad[0x324];
    float transparency;
public:
    float getTransparency() const { return transparency; }
};
class Decal : public Instance {
    char pad[0x140];
    TextureId texture;
    float specular;
    float shiny;
public:
    TextureId getTexture() const;
    float getSpecular() const { return specular; }
    float getShiny() const { return shiny; }
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
namespace ViewNew {
class View { char pad[0xc]; void* device; public: void* getDevice() const { return device; } };
class PartChunk {
protected:
    virtual ~PartChunk();
    char pad[0xb8];
    boost::shared_ptr<PartInstance> partInstance;
    PartMaterialRef material;
    bool materialInvalid;
    G3D::ReferenceCountedPointer<RenderBase::Mesh> mesh;
    View* view;
    void* specialShape;
};
class Decal : public PartChunk {
    boost::shared_ptr<RBX::Decal> decal;
public:
    PartMaterialRef getMaterial();
};
}
}
extern RBX::RenderBase::MaterialBase* createPartMaterial();
extern RBX::TextureProxyBase* createPartTexture(void*,const std::string&,bool);
extern const float decalTextureScale;

RBX::PartMaterialRef RBX::ViewNew::Decal::getMaterial() {
    int status;
    try {
        if (materialInvalid && partInstance) {
            std::string filename;
            ServiceProvider::find<ContentProvider>(partInstance.get())->requestContentFile(decal->getTexture(), &status, filename);
            if (status == 1) {
                material = createPartMaterial();
                TextureProxyBase* texture = createPartTexture(view->getDevice(), filename, false);
                float transparency = partInstance->getTransparency();
                material->appendLevel(TextureProxyBaseRef(texture), G3D::Color3::WHITE,
                    decal->getSpecular(), decal->getShiny(), 0.0f, 1.0f - transparency);
                texture->setFloat2c(decalTextureScale);
                materialInvalid = false;
            } else if (status == 2) {
                material = NULL;
                materialInvalid = false;
            }
        }
    } catch (...) {
    }
    return material;
}
