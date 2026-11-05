// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <limits>
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
namespace G3D {
inline double inf() { static const double i = std::numeric_limits<double>::infinity(); return i; }
template<class T> class Array {
public:
    T* data;
    int num;
    int numAllocated;
    Array() { num = 0; numAllocated = 0; data = 0; }
    ~Array();
};
class ReferenceCountedObject {
public:
    long ReferenceCountedObject_refCount;
    void ReferenceCountedObject_zeroWeakPointers();
    virtual ~ReferenceCountedObject();
};
template<class T> class ReferenceCountedPointer {
public:
    T* m_pointer;
    void setPointer(T* x);
    void zeroPointer()
    {
        if (m_pointer != 0) {
            if (InterlockedDecrement(&m_pointer->ReferenceCountedObject_refCount) == 0) {
                m_pointer->ReferenceCountedObject_zeroWeakPointers();
                delete m_pointer;
            }
        }
    }
    ReferenceCountedPointer() : m_pointer(0) {}
    ~ReferenceCountedPointer() { zeroPointer(); }
    ReferenceCountedPointer& operator=(const ReferenceCountedPointer& p) { setPointer(p.m_pointer); return *this; }
};
class Lighting : public ReferenceCountedObject {
public:
    static ReferenceCountedPointer<Lighting> create();
};
typedef ReferenceCountedPointer<Lighting> LightingRef;
class VAR { public: VAR(); ~VAR(); char pad[0x20]; };
class VARArea : public ReferenceCountedObject {};
class SkyParameters { public: SkyParameters(); double d; char pad[0xf0]; };
class Sky : public ReferenceCountedObject {};
}
namespace RBX { namespace Render {
class EffectSettings { public: char pad[0x14]; };
class ShadowThing { public: ShadowThing(); ~ShadowThing(); char pad[0x48]; };
class SceneBase {
public:
    virtual ~SceneBase();
    G3D::Array<void*> items;
    float extentX, extentY, factorX, factorY, scaleX, scaleY;
    SceneBase() : extentX(0.5f), extentY(extentX), factorX(1.0f), factorY(1.0f), scaleX(-1.0f), scaleY(scaleX) {}
};
class RenderScene : public SceneBase {
public:
    G3D::Array<void*> a0, a1, a2, a3, a4, a5;
    G3D::VAR shadowVAR;
    G3D::ReferenceCountedPointer<G3D::VARArea> shadowVARArea;
    EffectSettings effectSettings;
    G3D::LightingRef desiredLighting;
    G3D::LightingRef lighting;
    bool shadows;
    float cameraDistance;
    G3D::Array<void*> shadowArray;
    ShadowThing shadowThing;
    bool flag;
    G3D::ReferenceCountedPointer<G3D::Sky> sky;
    G3D::SkyParameters desiredSkyParams;
    G3D::SkyParameters skyParams;
    RenderScene();
    virtual ~RenderScene();
};
RenderScene::RenderScene()
    : shadows(false), cameraDistance(G3D::inf()), flag(false)
{
    desiredLighting = lighting = G3D::Lighting::create();
}
} }
