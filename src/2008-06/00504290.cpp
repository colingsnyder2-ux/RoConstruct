// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_render_proxies_native_shadow_array_ref40cd72f4949d224e.cpp

// Candidate translation unit (score above; library headers required).
// Native00504290, allocate render proxies. Names are codegen analogues.
// Actual G3D values/containers; opaque owner storage comes from native accesses.
#include <RenderLib/Mesh.h>
#include <G3D/GCamera.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/ReferenceCount.h>
#include <G3D/Array.h>
#include <GLG3D/Texture.h>
#include <algorithm>
#include <cmath>
#include <cstddef>

template<class T> static inline T& proxyField(void* p,unsigned offset) {
    return *reinterpret_cast<T*>(static_cast<char*>(p)+offset);
}
namespace RBX { namespace RenderBase {
class MaterialBase : public G3D::ReferenceCountedObject {
public:
    class Level {
    public:
        virtual bool isEmptyLevel() const;
        virtual ~Level();
        // MSVC reverses each overload group: engine form is native slot8.
        virtual TextureProxyBaseRef baseTexture() const;
        virtual G3D::TextureRef baseTexture(G3D::RenderDevice*) const;
        virtual void setBaseTexture(TextureProxyBaseRef);
        virtual G3D::TextureRef matte(G3D::RenderDevice*) const;
        virtual const G3D::Color3& color() const;
        virtual float specular() const;
        virtual float shiny() const;
        virtual float reflect() const;
        virtual float transparent() const;
    };
    virtual ~MaterialBase();
    virtual const Level& appendEmptyLevel();
    virtual const Level& appendLevel(TextureProxyBaseRef,G3D::Color3,float,float,float,float);
    virtual const Level& appendLevel(G3D::Color3,float,float,float,float);
    virtual size_t levelCount() const;
    virtual Level& getLevel(int);
    virtual const Level* detailLevel(float) const;
    virtual bool veryTransparent() const;
};
// Proven primary virtual prefix only; no complete Chunk layout/allocation claim.
class Chunk : public G3D::ReferenceCountedObject {
public:
    virtual ~Chunk();
    virtual bool cachesShadows() const;
    virtual void renderShadows(G3D::RenderDevice*,const G3D::GLight&,bool,float);
    virtual bool castsShadows() const;
    virtual bool cullable() const;
    virtual G3D::ReferenceCountedPointer<MaterialBase> getMaterial();
    virtual G3D::ReferenceCountedPointer<Render::Mesh> getMesh();
    virtual const G3D::CoordinateFrame& cframe();
};
}}
namespace RBX { namespace Render {
// Genuine RenderSurface field order, with2008 MaterialBase::Level interface.
class RenderSurface {
public:
    G3D::CoordinateFrame cframe;
    float z;
    const RenderBase::MaterialBase::Level* material;
    float polygonOffset;
    const Mesh::Level* mesh;
    G3D::ReferenceCountedPointer<Mesh> fullMesh;
    RenderSurface():material(0),mesh(0) {}
};
class RenderScene {
public:
    float farCullZ() const { return proxyField<float>(const_cast<RenderScene*>(this),0x2dc); }
    void allocateProxies(G3D::RenderDevice*,const G3D::GCamera&);
};
}}
typedef char NativeRenderSurfaceSize[sizeof(RBX::Render::RenderSurface)==68?1:-1];
typedef char NativeRenderSurfaceMaterial[offsetof(RBX::Render::RenderSurface,material)==0x34?1:-1];
typedef char NativeRenderSurfaceMesh[offsetof(RBX::Render::RenderSurface,mesh)==0x3c?1:-1];
typedef char NativeRenderSurfaceFullMesh[offsetof(RBX::Render::RenderSurface,fullMesh)==0x40?1:-1];
typedef char NativeProxyArraySize[sizeof(G3D::Array<RBX::Render::RenderSurface>)==12?1:-1];

static inline float proxyDetailLevel(float x,float low,float high) {
    return G3D::clamp(1.0f-(x-low)/(high-low),0.0f,1.0f);
}

void RBX::Render::RenderScene::allocateProxies(G3D::RenderDevice* rd,const G3D::GCamera& camera) {
    typedef G3D::ReferenceCountedPointer<RenderBase::Chunk> ChunkRef;
#define chunks proxyField<G3D::Array<ChunkRef> >(this,8)
#define proxies proxyField<G3D::Array<RenderSurface> >(this,0x268)
#define shadowProxies proxyField<G3D::Array<RenderSurface> >(this,0x298)
#define shadowChunks proxyField<G3D::Array<ChunkRef> >(this,0x2a4)
    G3D::CoordinateFrame cameraFrame;
    camera.getCoordinateFrame(cameraFrame);
    float farZ=std::max(farCullZ(),camera.getFarPlaneZ());
    float nearZ=camera.getNearPlaneZ();
    for(int p=0;p<chunks.size();++p) {
        RenderBase::Chunk* chunk=chunks[p].getPointer();
        if(!chunk) continue;
        bool hasMesh=chunk->getMesh().notNull();
        bool hasMaterial=chunk->getMaterial().notNull();
        if(!hasMesh || !hasMaterial) continue;
        const G3D::CoordinateFrame& frame=chunk->cframe();
        G3D::Vector3 cspace=cameraFrame.pointToObjectSpace(frame.translation);
        bool farCulled=cspace.z+proxyField<float>(chunk,0x1c)<farZ && chunk->cullable();
        bool nearCulled=cspace.z-proxyField<float>(chunk,0x1c)>nearZ;
        bool shadowFarCulled=cspace.z+proxyField<float>(chunk,0x1c)<farZ*1.2f && chunk->cullable();
        if(chunk->castsShadows() && !shadowFarCulled && !chunk->getMaterial()->veryTransparent()) {
            if(chunk->cachesShadows()) shadowChunks.append(chunks[p]);
            else {
                G3D::Array<RenderSurface>& shadows=shadowProxies;
                shadows.resize(shadows.size()+1,false);
                RenderSurface& proxy=shadows.last();
                proxy.material=0;
                proxy.cframe=frame;
                proxy.mesh=chunk->getMesh()->dropShadowMesh().getPointer();
                proxy.fullMesh=chunk->getMesh();
            }
        }
        if(!farCulled && !nearCulled) {
            for(int level=0;level<(int)chunk->getMaterial()->levelCount();++level) {
                if(chunk->getMaterial()->getLevel(level).isEmptyLevel()) continue;
                RenderSurface proxy;
                proxy.cframe=frame;
                proxy.polygonOffset=proxyField<float>(chunk,0x18);
                proxy.z=cspace.z-proxyField<float>(chunk,0x18);
                proxy.fullMesh=chunk->getMesh();
                proxy.material=&chunk->getMaterial()->getLevel(level);
                if(proxy.material) {
                    proxy.material->baseTexture(rd);
                    float raw=proxyDetailLevel(fabsf(proxy.z),-nearZ,-farZ)+proxyField<float>(this,0x2e4);
                    float lod=G3D::clamp(raw,0.0f,1.0f);
                    proxy.mesh=chunk->getMesh()->detailLevel(lod).getPointer();
                    proxies.append(proxy);
                }
            }
        }
    }
#undef chunks
#undef proxies
#undef shadowProxies
#undef shadowChunks
}
