// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
namespace G3D {
template<class T> class ReferenceCountedPointer {
    T* m_pointer;
public:
    ReferenceCountedPointer(const ReferenceCountedPointer& p);

};
}
namespace RBX {
class Texture;
class ProxyBase {
public:
    ProxyBase(int a, G3D::ReferenceCountedPointer<Texture> t);
    ~ProxyBase();
};
class TextureProxy : public ProxyBase {
public:
    TextureProxy(int a, const G3D::ReferenceCountedPointer<Texture>& t);
    void init();
};
TextureProxy::TextureProxy(int a, const G3D::ReferenceCountedPointer<Texture>& t) : ProxyBase(a, t)
{
    init();
}
}
