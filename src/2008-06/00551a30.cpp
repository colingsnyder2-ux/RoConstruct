// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Factory analog for 00551a30: selector 00942ec4 picks RenderNew (0x64 bytes,
// ctor 007ae4b0) or Render (0x58 bytes, ctor 007b8fb0) texture proxies.
#include <exception>

class TextureProxyBase {
public:
    virtual ~TextureProxyBase();
};

namespace RenderNew { class TextureProxy : public TextureProxyBase { public: TextureProxy(int owner, int texture); char data[0x60]; }; }
namespace Render { class TextureProxy : public TextureProxyBase { public: TextureProxy(int owner, int texture); char data[0x54]; }; }

extern int materialFactoryType;

TextureProxyBase* createTextureProxy(int owner, int texture)
{
    if (materialFactoryType == 0)
        return new RenderNew::TextureProxy(owner, texture);
    else if (materialFactoryType == 1)
        return new Render::TextureProxy(owner, texture);
    else
        throw std::exception("Invalid factory type");
}
