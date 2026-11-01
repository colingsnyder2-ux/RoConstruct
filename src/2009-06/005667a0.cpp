// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace G3D {
class AtomicInt32 {
    volatile long _value;
public:
    unsigned int decrement() { return InterlockedDecrement(&_value) != 0; }
};
class ReferenceCountedObject {
public:
    AtomicInt32 ReferenceCountedObject_refCount;
    void* ReferenceCountedObject_weakPointer;
    void ReferenceCountedObject_zeroWeakPointers();
    virtual ~ReferenceCountedObject() {}
};
template <class T>
class ReferenceCountedPointer {
    T* m_pointer;
    void zeroPointer() {
        if (m_pointer != 0) {
            if (m_pointer->ReferenceCountedObject_refCount.decrement() == 0) {
                m_pointer->ReferenceCountedObject_zeroWeakPointers();
                delete m_pointer;
            }
            m_pointer = 0;
        }
    }
    void setPointer(T* x);
public:
    inline ~ReferenceCountedPointer() { zeroPointer(); }
    inline const ReferenceCountedPointer<T>& operator=(const ReferenceCountedPointer<T>& p) {
        setPointer(p.m_pointer);
        return *this;
    }
};
class Lighting : public ReferenceCountedObject { };
class LightingParameters { public: char data[248]; };
}
namespace RBX { namespace Render {
class EffectSettings {
public:
    G3D::ReferenceCountedPointer<G3D::Lighting> update(bool shadows, float cameraDistanceFromCharacters,
        const G3D::ReferenceCountedPointer<G3D::Lighting>& desiredLighting,
        const G3D::LightingParameters& desiredSkyParameters, G3D::LightingParameters& outSkyParameters);
};
class RenderScene {
public:
    char pad[0x94];
    EffectSettings effectSettings;
    char pad2[0xa8 - 0x95];
    G3D::ReferenceCountedPointer<G3D::Lighting> desiredLighting;
    G3D::ReferenceCountedPointer<G3D::Lighting> lighting;
    bool shadows;
    float cameraDistance;
    char pad3[0x118 - 0xb8];
    G3D::LightingParameters desiredSkyParameters;
    G3D::LightingParameters skyParameters;
    void setLighting(const G3D::ReferenceCountedPointer<G3D::Lighting>& L);
};
void RenderScene::setLighting(const G3D::ReferenceCountedPointer<G3D::Lighting>& L)
{
    desiredLighting = L;
    lighting = effectSettings.update(shadows, cameraDistance, desiredLighting, desiredSkyParameters, skyParameters);
}
}}
