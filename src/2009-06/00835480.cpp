// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
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
    void setPointer(T* x);
    void zeroPointer() {
        if (m_pointer != 0) {
            if (InterlockedDecrement(&m_pointer->ReferenceCountedObject_refCount) == 0) {
                m_pointer->ReferenceCountedObject_zeroWeakPointers();
                delete m_pointer;
            }
            m_pointer = 0;
        }
    }
    ReferenceCountedPointer() : m_pointer(0) {}
    ReferenceCountedPointer(const ReferenceCountedPointer& p) : m_pointer(0) { setPointer(p.m_pointer); }
    ~ReferenceCountedPointer() { zeroPointer(); }
};
class Texture : public ReferenceCountedObject {};
class TextureManager;
class Color3 { public: float r, g, b; };
}
namespace Ogre { class __declspec(dllimport) TexturePtr { public: TexturePtr(); ~TexturePtr(); void* p[4]; }; }
namespace boost { template<class T> class shared_ptr { public: T* px; void* pn; shared_ptr() : px(0), pn(0) {} ~shared_ptr(); }; }
namespace RBX { namespace RenderNew {
class TextureProxyBase : public G3D::ReferenceCountedObject {
public:
    TextureProxyBase();
    int pad8;
    std::string filename;
    int pad28, pad2c;
};
struct Extra;
class TextureProxy : public TextureProxyBase {
protected:
    G3D::ReferenceCountedPointer<G3D::Texture> texture;
    bool loaded;
    G3D::TextureManager* textureManager;
    bool tiled;
    bool flag2009;
    G3D::ReferenceCountedPointer<TextureProxy> root;
    G3D::ReferenceCountedPointer<TextureProxy> shadeTexture;
    G3D::Color3 shadeColor;
    boost::shared_ptr<Extra> extra;
    Ogre::TexturePtr ogreTexture;
    TextureProxy(G3D::ReferenceCountedPointer<TextureProxy> root);
};
TextureProxy::TextureProxy(G3D::ReferenceCountedPointer<TextureProxy> root)
    : root(root), loaded(false), textureManager(0), flag2009(false)
{
    this->filename = "";
}
}}
