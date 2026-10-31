#pragma once
#include <Ogre.h>
#include <G3D/ReferenceCount.h>
#include <G3D/Array.h>
#include <G3D/Color3.h>
#include <G3D/Vector2.h>
#include <GLG3D/Texture.h>
#include "v8datamodel/BrickColor.h"
#include <string>
namespace PlayerNativeMaterial {
class TextureProxyBase;
typedef G3D::ReferenceCountedPointer<TextureProxyBase> TextureRef;
// Native RTTI: TextureProxyBase -> G3D::ReferenceCountedObject.
class TextureProxyBase : public G3D::ReferenceCountedObject {
public:
    std::string filename;
    int value28;
    float value2c;
    TextureProxyBase();
    virtual ~TextureProxyBase();
    virtual void setValue28(int);
    virtual int getValue28() const;
    virtual void setValue2c(float);
    virtual float getValue2c() const;
    virtual G3D::Vector2 getSize() = 0;
    virtual G3D::TextureRef resolve(void* engine) = 0;
    virtual TextureRef shade(const G3D::Color3&,const TextureRef&) = 0;
};
class TextureProxy : public TextureProxyBase {
public:
    G3D::TextureRef texture;
    bool loaded;
    void* context; // Observed pointer; no fabricated VisualEngine declaration.
    bool tiled;
    TextureRef root;
    TextureRef shadeTexture;
    G3D::Color3 shadeColor;
    Ogre::TexturePtr ogreTexture;
    TextureProxy(void*,const std::string&,bool);
    explicit TextureProxy(TextureRef);
    ~TextureProxy();
    G3D::Vector2 getSize();
    G3D::TextureRef resolve(void*);
    TextureRef shade(const G3D::Color3&,const TextureRef&);
    static void shadePixel(const G3D::Color3uint8&,G3D::Color3uint8&);
};
class MegaTextureProxy : public TextureProxy {
public:
    float stripWidth;
    MegaTextureProxy(void*,const std::string&);
    G3D::TextureRef resolve(void*);
};
void collectUnusedTextures();
// Native RTTI proves both abstract interface bases; they add no data.
class MaterialBase : public G3D::ReferenceCountedObject {
public:
    class Level {
    public:
        virtual bool isEmptyLevel() const = 0;
        virtual ~Level();
        virtual TextureRef baseTexture() const = 0;
        virtual G3D::TextureRef baseTexture(void*) const = 0;
        virtual void setBaseTexture(TextureRef) = 0;
        virtual G3D::TextureRef matte(void*) const = 0;
        virtual const G3D::Color3& color() const = 0;
        virtual float specular() const = 0;
        virtual float shiny() const = 0;
        virtual float reflect() const = 0;
        virtual float transparent() const = 0;
    };
    virtual ~MaterialBase();
    virtual const Level& appendEmptyLevel() = 0;
    virtual const Level& appendLevel(TextureRef,G3D::Color3,float,float,float,float) = 0;
    virtual const Level& appendLevel(G3D::Color3,float,float,float,float) = 0;
    virtual int levelCount() const = 0;
    virtual Level& getLevel(int) = 0;
    virtual const Level* detailLevel(float) const = 0;
    virtual bool veryTransparent() const = 0;
};
typedef G3D::ReferenceCountedPointer<MaterialBase> MaterialRef;
class Material : public MaterialBase {
public:
    class Level : public MaterialBase::Level {
    public:
        bool empty;
        TextureRef matteTexture;
        TextureRef texture;
        G3D::Color3 colorValue;
        float specularValue,shinyValue,reflectance,transparency;
        Ogre::MaterialPtr backend;
        Level();
        Level(TextureRef,G3D::Color3,float,float,float,float);
        ~Level();
        bool isEmptyLevel() const;
        TextureRef baseTexture() const;
        G3D::TextureRef baseTexture(void*) const;
        void setBaseTexture(TextureRef);
        G3D::TextureRef matte(void*) const;
        const G3D::Color3& color() const;
        float specular() const;
        float shiny() const;
        float reflect() const;
        float transparent() const;
    };
    G3D::Array<Level> levels;
    const MaterialBase::Level& appendEmptyLevel();
    const MaterialBase::Level& appendLevel(TextureRef,G3D::Color3,float,float,float,float);
    const MaterialBase::Level& appendLevel(G3D::Color3,float,float,float,float);
    int levelCount() const;
    MaterialBase::Level& getLevel(int);
    const MaterialBase::Level* detailLevel(float) const;
    bool veryTransparent() const;
};
struct Attributes {
    RBX::BrickColor color;
    float transparency,reflectance;
    bool operator<(const Attributes&) const;
};
class MaterialFactory {
public:
    TextureRef megaTexture,surfacesTexture,fileMeshTexture;
    MaterialRef fileMeshMaterial;
    MaterialFactory(void*,const std::string& surfaces,const std::string& file,const std::string& mega);
    MaterialRef getMaterial(Attributes);
    MaterialRef getMegaMaterial(Attributes);
};
}
