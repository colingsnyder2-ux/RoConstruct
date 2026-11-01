// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile *);
namespace G3D {
class ReferenceCountedObject {
public:
    long ReferenceCountedObject_refCount;
    void ReferenceCountedObject_zeroWeakPointers();
    virtual ~ReferenceCountedObject();
};
template<class T> class ReferenceCountedPointer {
public:
    T* m_pointer;
    void zero() {
        if (m_pointer != 0) {
            if (InterlockedDecrement(&m_pointer->ReferenceCountedObject_refCount) == 0) {
                m_pointer->ReferenceCountedObject_zeroWeakPointers();
                delete m_pointer;
            }
            m_pointer = 0;
        }
    }
};
}
namespace RBX {
class Material : public G3D::ReferenceCountedObject {};
class MaterialBaseRefMaterialAdapter {
    char pad[8];
    G3D::ReferenceCountedPointer<Material>* ref;
public:
    void release();
};
void MaterialBaseRefMaterialAdapter::release() { ref->zero(); }
}
