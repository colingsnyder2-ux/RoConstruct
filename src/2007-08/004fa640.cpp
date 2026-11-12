// from server: 100% by EspClaude
// roc 2007-08 004fa640  (trial): RBX::Render::TextureProxy(TextureProxyRef root)
//   : loaded(false), textureManager(NULL), root(root) { filename = ""; }
// Layout from target: texture +0x28, loaded +0x2c, textureManager +0x30,
// root +0x38 (copy: m_pointer=0 then setPointer 0x474f70), shadeTexture +0x3c,
// filename (std::string) +0xc assigned "" via msvcp80 operator=(const char*).
// Base ctor TextureProxyBase() is the out-of-line 0x4cfd40.
// The by-value root parameter is released at the end (G3D 6.09 zeroPointer:
// InterlockedDecrement, zeroWeakPointers 0x457dd0, virtual scalar-deleting dtor).
#include <string>

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

namespace G3D {

class AtomicInt32 {
    volatile long m_value;
public:
    AtomicInt32(long x) : m_value(x) {}
    void increment() { InterlockedIncrement(&m_value); }
    long decrement() { return InterlockedDecrement(&m_value); }
};

class _WeakPtrLinkedList;

class ReferenceCountedObject {
public:
    AtomicInt32 ReferenceCountedObject_refCount;
    _WeakPtrLinkedList* ReferenceCountedObject_weakPointer;
protected:
    ReferenceCountedObject() : ReferenceCountedObject_refCount(0), ReferenceCountedObject_weakPointer(0) {}
public:
    void ReferenceCountedObject_zeroWeakPointers();
    virtual ~ReferenceCountedObject() {}
};

template <class T>
class ReferenceCountedPointer {
    T* m_pointer;

    void zeroPointer() {
        if (m_pointer != NULL) {
            if (m_pointer->ReferenceCountedObject_refCount.decrement() == 0) {
                m_pointer->ReferenceCountedObject_zeroWeakPointers();
                delete m_pointer;
            }
            m_pointer = NULL;
        }
    }
    void setPointer(T* x);
public:
    inline ReferenceCountedPointer() : m_pointer(NULL) {}
    inline ReferenceCountedPointer(const ReferenceCountedPointer<T>& p) : m_pointer(NULL) {
        setPointer(p.m_pointer);
    }
    inline ~ReferenceCountedPointer() { zeroPointer(); }
};

class Texture : public ReferenceCountedObject {
public:
    virtual ~Texture();
};
class TextureManager;

}

namespace RBX {

class TextureProxyBase : public G3D::ReferenceCountedObject {
public:
    std::string filename; // 0x0c
    TextureProxyBase();
    virtual ~TextureProxyBase() {}
};

namespace Render {

class TextureProxy;
typedef G3D::ReferenceCountedPointer<TextureProxy> TextureProxyRef;

class TextureProxy : public TextureProxyBase {
protected:
    G3D::ReferenceCountedPointer<G3D::Texture> texture; // 0x28
    bool loaded;                                        // 0x2c
    G3D::TextureManager* textureManager;                // 0x30
    char pad34[4];                                      // 0x34 (unused here)
    TextureProxyRef root;                               // 0x38
    TextureProxyRef shadeTexture;                       // 0x3c
public:
    TextureProxy(TextureProxyRef root);
};

TextureProxy::TextureProxy(TextureProxyRef root)
    : loaded(false), textureManager(NULL), root(root)
{
    filename = "";
}

}
}
