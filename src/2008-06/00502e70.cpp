// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
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
private:
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
    ReferenceCountedPointer() : m_pointer(0) {}
    ~ReferenceCountedPointer() { zeroPointer(); }
    const ReferenceCountedPointer<T>& operator=(const ReferenceCountedPointer<T>& p) {
        setPointer(p.m_pointer);
        return *this;
    }
};
class Lighting : public ReferenceCountedObject {};
class LightingParameters { char data[0xf8]; };
}
namespace RBX {
namespace Render {
class EffectSettings {
public:
    G3D::ReferenceCountedPointer<G3D::Lighting> update(float, float, bool, float, const G3D::ReferenceCountedPointer<G3D::Lighting>&, const G3D::LightingParameters&, G3D::LightingParameters&);
};
class RenderScene {
    char pad0[0x24];
    float shadingQuality;    // 0x24
    float meshDetail;        // 0x28
    char pad1[0x2d4 - 0x2c];
    EffectSettings effectSettings; // 0x2d4
    char pad2[0x2e8 - 0x2d5];
    G3D::ReferenceCountedPointer<G3D::Lighting> desiredLighting; // 0x2e8
    G3D::ReferenceCountedPointer<G3D::Lighting> lighting;        // 0x2ec
    bool shadows;            // 0x2f0
    float cameraDistance;    // 0x2f4
    char pad3[0x310 - 0x2f8];
    G3D::LightingParameters desiredSkyParameters; // 0x310
    G3D::LightingParameters skyParameters;        // 0x408
public:
    void setLighting(const G3D::ReferenceCountedPointer<G3D::Lighting>& L);
};
void RenderScene::setLighting(const G3D::ReferenceCountedPointer<G3D::Lighting>& L)
{
    desiredLighting = L;
    lighting = effectSettings.update(shadingQuality, meshDetail, shadows, cameraDistance, desiredLighting, desiredSkyParameters, skyParameters);
}
}
}
