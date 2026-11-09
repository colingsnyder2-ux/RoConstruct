// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_adorn_owner_native_particle_localb0ade42fadd1538d.cpp

// Candidate translation unit (score above; library headers required).
// Native324B allocation0045b425, ctor674210, dtor673a90.
#undef OGRE_NONCLIENT_BUILD
#include "roc_adorn_native_novtable_interface91b88275e0007f5c.cpp"
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/Ogre.h"
#include <vector>
#include <map>
#include <cstdio>
#include <exception>
namespace Ogre {
class VisualEngine;
class RbxSubEntity : public SubEntity, public ShadowCaster {
public:
    virtual ~RbxSubEntity();
    // 0084e90c slots 48/4c; bodies 00685820/00685830.
    virtual void setFloat138(float);
    virtual float getFloat138() const;
    void setLodMesh(unsigned int, SubMesh*); // 006850b0
    SubMesh* getLodMesh(unsigned int);       // 006850d0
    void setLod(unsigned int);              // 006850f0
};
class RbxSceneNode : public SceneNode {
    typedef std::map<unsigned long, Matrix4*> TransformMap;
    mutable TransformMap transforms;
public:
    RbxSceneNode(SceneManager*, const String&);
    virtual ~RbxSceneNode();
    virtual void setTransform(unsigned long, const Matrix4&);
    virtual const Matrix4& getTransform(unsigned long) const;
    virtual bool hasTransform(unsigned long) const;
    virtual void setSphere(unsigned long, const Sphere&);
    virtual const Sphere& getSphere(unsigned long) const;
};
class RbxEntityEntry; // Native 2a4 member is a vector; element never instantiated here.
class RbxEntity : public Entity {
    void* field274;
    bool field278, field279, field27a;
    AxisAlignedBox field27c;
    float field29c;
    int field2a0;
    std::vector<RbxEntityEntry> field2a4;
public:
    RbxEntity();
    virtual ~RbxEntity();
    void setMesh(MeshPtr);                 // 0067c520
    void setContext18(void*);              // 0067c510
    RbxSubEntity* addSubEntity(SubMesh*, unsigned int); // 0067d9b0
    void mergeBounds(AxisAlignedBox);      // 007a9c40
};
}

namespace Ogre {
// Opaque pointee only.684b10 initializes character metrics at0; no font vptr.
class RbxFont { public: ~RbxFont(); };
SharedPtr<RbxFont> loadRbxFont(const std::string&); //684eb0 cdecl hidden result.
}
namespace RBX {
extern Ogre::SharedPtr<Ogre::RbxFont> nativeAdornFont; //962da8.
extern int nativeAdornCount; //97db28.
std::string nativeResolveFile(const char*); //55d0b0.
class AdornRbxGfx : public Adorn {
public:

    void* engine;                         // 04, constructor arg.
    std::string label;                    // 08.
    Ogre::MaterialPtr textureMaterial;    // 24.
    Ogre::SceneNode* root;                // 30.
    Ogre::RbxSceneNode* renderNode;        // 34.
    Ogre::MaterialPtr solidMaterial;      // 38.
    int particleCount;                    // 44,670d50 count sum.
    std::vector<Ogre::RbxSubEntity*> freeSubEntities; //48,671d60.
    std::vector<Ogre::RbxSubEntity*> activeSubEntities; //60.
    typedef std::map<std::string,Ogre::MeshPtr> MeshCache;
    MeshCache meshes;                     // 78.
    Ogre::RbxEntity* entity;               // 98.
    Ogre::SceneNode* explosionRoot;        // 9c.
    std::vector<Ogre::SceneNode*> explosionNodes; //a0.
    typedef std::map<std::string,Ogre::SceneNode*> NodeCache;
    NodeCache explosions;                 // b8.
    Ogre::SceneNode* sparkleRoot;          // d8.
    std::vector<Ogre::SceneNode*> sparkleNodes; //dc.
    NodeCache sparkles;                    // f4.
    G3D::CoordinateFrame coordinateFrame; // 114.

    AdornRbxGfx(void*);
    virtual ~AdornRbxGfx();
		virtual G3D::ReferenceCountedPointer<TextureProxyBase> createTextureProxy(const std::string& filename);
		virtual void prepareRenderPass();
		virtual void finishRenderPass();
		virtual G3D::Rect2D getViewport() const;
		virtual int getWidth() const;
		virtual int getHeight() const;
		virtual void setTexture(int id, G3D::ReferenceCountedPointer<TextureProxyBase> _texture);
		virtual G3D::Rect2D getTextureSize(G3D::ReferenceCountedPointer<TextureProxyBase> _texture) const;
		virtual void line2d(const G3D::Vector2& p0, const G3D::Vector2& p1, const G3D::Color4& color) const;
		virtual void outlineRect2d(const G3D::Rect2D& rect, float thick, const G3D::Color4& color) const;
		virtual void rect2d(const G3D::Rect2D& rect, const G3D::Color4& color) const;
		virtual G3D::Vector2 get2DStringBounds(const std::string& s, double size, Spacing spacing) const;
		virtual G3D::Vector2 drawFont2D(const std::string& s, const G3D::Vector2& pos2d, double size, const G3D::Color4& color, const G3D::Color4& outline, XAlign xalign, YAlign yalign, Spacing spacing) const;
		virtual void setObjectToWorldMatrix(const G3D::CoordinateFrame& c);
		virtual void setColor(const G3D::Color4& color);
		virtual void box(const G3D::AABox& box, const G3D::Color4& solidColor, const G3D::Color4& wireColor);
		virtual void sphere(const G3D::Sphere& sphere, const G3D::Color4& solidColor, const G3D::Color4& wireColor);
		virtual void explosion(const G3D::Sphere& sph, const G3D::Color4& solidColor, const G3D::Color4& wireColor);
		virtual void sparkle(); // Native00674790, vtable4c.
		virtual void cylinderAlongX(float radius, float length, const G3D::Color4& solidColor, const G3D::Color4& wireColor);
		virtual void ray(const G3D::Ray& ray, const G3D::Color4& color, float scale);
		virtual void lineSegment(const G3D::LineSegment& lineSegment, const G3D::Color4& color, float scale);
		virtual void axes(const G3D::Color4& xColor, const G3D::Color4& yColor, const G3D::Color4& zColor, float scale);
		virtual void quad(const G3D::Vector3& v0, const G3D::Vector3& v1, const G3D::Vector3& v2, const G3D::Vector3& v3, const G3D::Color4& color);
    Ogre::SceneManager* sceneManager() {return *(Ogre::SceneManager**)((char*)engine+4);}
};
typedef char NativeAdornSize[sizeof(AdornRbxGfx)==0x144?1:-1];
typedef char NativeEntitySize[sizeof(Ogre::RbxEntity)==0x2bc?1:-1];
typedef char NativeSceneNodeSize[sizeof(Ogre::RbxSceneNode)==0x248?1:-1];
AdornRbxGfx::AdornRbxGfx(void* context)
    : label(""), meshes(MeshCache::key_compare(),MeshCache::allocator_type()),
      explosionRoot(0), explosions(NodeCache::key_compare(),NodeCache::allocator_type()),
      sparkleRoot(0), sparkles(NodeCache::key_compare(),NodeCache::allocator_type()) {
    engine=context;
    if(nativeAdornFont.isNull()) {
        try { nativeAdornFont=Ogre::loadRbxFont(nativeResolveFile("Fonts\\comics.fnt")); }
        catch(std::exception&) {}
    }
    char name[8];
    _snprintf(name,8,"a3dr%d",nativeAdornCount++);
    root=sceneManager()->createSceneNode(name);
    sceneManager()->getRootSceneNode()->addChild(root);
    renderNode=new Ogre::RbxSceneNode(*(Ogre::SceneManager**)((char*)context+4),std::string(name)+"opt");
    sceneManager()->getRootSceneNode()->addChild(renderNode);
    entity=new Ogre::RbxEntity;
    *(bool*)((char*)entity+0x278)=false;
    *(bool*)((char*)entity+0x27a)=false;
    entity->setContext18((char*)engine+0x18);
    renderNode->attachObject(entity);
    Ogre::MeshPtr mesh=Ogre::MeshManager::getSingleton().getByName("rbxdummymesh");
    if(mesh.isNull()) mesh=Ogre::MeshManager::getSingleton().create("rbxdummymesh","General");
    entity->setMesh(mesh);
    _snprintf(name,8,"loff%d",nativeAdornCount-1);
    solidMaterial=Ogre::MaterialManager::getSingleton().create(name,"General");
    solidMaterial->setLightingEnabled(false);
}
AdornRbxGfx::~AdornRbxGfx() {
    meshes.clear();
    sceneManager()->getRootSceneNode()->removeAndDestroyChild(root->getName());
    sceneManager()->getRootSceneNode()->removeChild(renderNode);
    delete renderNode;
    delete entity;
    for(int i=0;i<(int)freeSubEntities.size();++i) delete freeSubEntities[i];
    for(int i=0;i<(int)activeSubEntities.size();++i) delete activeSubEntities[i];
    for(int i=0;i<(int)explosionNodes.size();++i) {
        Ogre::ParticleSystem* system=static_cast<Ogre::ParticleSystem*>(explosionNodes[i]->getAttachedObject(0));
        sceneManager()->destroyParticleSystem(system->getName());
        sceneManager()->destroySceneNode(explosionNodes[i]->getName());
    }
    if(explosionRoot) sceneManager()->destroySceneNode(explosionRoot->getName());
    for(int i=0;i<(int)sparkleNodes.size();++i) {
        Ogre::ParticleSystem* system=static_cast<Ogre::ParticleSystem*>(sparkleNodes[i]->getAttachedObject(0));
        sceneManager()->destroyParticleSystem(system->getName());
        sceneManager()->destroySceneNode(sparkleNodes[i]->getName());
    }
    if(sparkleRoot) sceneManager()->destroySceneNode(sparkleRoot->getName());
    explosionNodes.clear();
    explosions.clear();
    sparkleNodes.clear();
    sparkles.clear();
}
}
