// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace G3D {
template<class T> class ReferenceCountedPointer {
public:
    T* m_pointer;
    void setPointer(T* x);
    ReferenceCountedPointer(T* p) : m_pointer(0) { setPointer(p); }
    ~ReferenceCountedPointer();
};
}
namespace RBX {
class TextureProxyBase { public: virtual ~TextureProxyBase(); };
typedef G3D::ReferenceCountedPointer<TextureProxyBase> TextureProxyBaseRef;
namespace Render {
class TextureManager { public: int x; };
class TextureProxy : public TextureProxyBase {
public:
    TextureProxy(TextureManager& m, const std::string& f, bool b);
    char pad[0x54 - 4];
};
}
class Adorn { public: virtual TextureProxyBaseRef createTextureProxy(const std::string& filename) = 0; };
class AdornG3D : public Adorn {
public:
    int rd;
    Render::TextureManager textureManager;
    virtual TextureProxyBaseRef createTextureProxy(const std::string& filename);
};
TextureProxyBaseRef AdornG3D::createTextureProxy(const std::string& filename)
{
    Render::TextureProxy* proxy = new Render::TextureProxy(textureManager, filename, false);
    return TextureProxyBaseRef(proxy);
}
}
