// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace G3D {
class Color3 { public: float r, g, b; Color3() {} Color3(const Color3& o) { r = o.r; g = o.g; b = o.b; } };
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
    ReferenceCountedPointer(const ReferenceCountedPointer<T>& p) : m_pointer(0) { setPointer(p.m_pointer); }
    ~ReferenceCountedPointer() { zeroPointer(); }
};
template <class T>
class Array {
    T* data;
    int num;
    int numAllocated;
public:
    void push_back(const T& value);
    T& last() { return data[num - 1]; }
};
}
namespace RBX {
namespace Render {
class TextureProxy : public G3D::ReferenceCountedObject {};
class Material {
public:
    class Level {
        friend class Material;
        char data[0x38];
        Level(G3D::ReferenceCountedPointer<TextureProxy> baseTexture, G3D::Color3 color, float specular, float shiny, float reflect, float transparent);
    public:
        ~Level();
    };
    const Level& appendLevel(G3D::ReferenceCountedPointer<TextureProxy> baseTexture, G3D::Color3 color, float specular, float shiny, float reflect, float transparent);
private:
    char pad[0xc];
    G3D::Array<Level> levels;
};
const Material::Level& Material::appendLevel(G3D::ReferenceCountedPointer<TextureProxy> baseTexture, G3D::Color3 color, float specular, float shiny, float reflect, float transparent)
{
    levels.push_back(Material::Level(baseTexture, color, specular, shiny, reflect, transparent));
    return levels.last();
}
}
}
