// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class ReferenceCountedObject { public: virtual ~ReferenceCountedObject(); int refCount; };
template<class T> class ReferenceCountedPointer {
	T* m_pointer;
	void setPointer(T* x);
public:
	ReferenceCountedPointer() : m_pointer(0) {}
	ReferenceCountedPointer(T* p) : m_pointer(0) { setPointer(p); }
	~ReferenceCountedPointer();
	ReferenceCountedPointer& operator=(T* p) { setPointer(p); return *this; }
	T* pointer() const { return m_pointer; }
};
class Vector3 { public: float x, y, z; Vector3& operator=(const Vector3& o) { x = o.x; y = o.y; z = o.z; return *this; } };
}
namespace RBX {
class TextureProxyBase : public G3D::ReferenceCountedObject { public: virtual ~TextureProxyBase(); };
namespace RbxG3D { class TextureProxy : public TextureProxyBase { public: virtual ~TextureProxy(); }; }
class ProxyBase : public G3D::ReferenceCountedObject { public: ProxyBase(); char pad[0x30 - 8]; };
class Proxy : public ProxyBase {
public:
	Proxy(G3D::ReferenceCountedPointer<RbxG3D::TextureProxy> tex);
	virtual ~Proxy();
	G3D::ReferenceCountedPointer<Proxy> clone(const G3D::Vector3& v, const G3D::ReferenceCountedPointer<TextureProxyBase>& tex);
	int f30; bool f34; int f38; char f3c[4];
	G3D::ReferenceCountedPointer<RbxG3D::TextureProxy> texture;
	G3D::ReferenceCountedPointer<Proxy> parent;
	G3D::Vector3 position;
	
};
G3D::ReferenceCountedPointer<Proxy> Proxy::clone(const G3D::Vector3& v, const G3D::ReferenceCountedPointer<TextureProxyBase>& tex)
{
	RbxG3D::TextureProxy* t = dynamic_cast<RbxG3D::TextureProxy*>(tex.pointer());
	Proxy* p = new Proxy(t);
	p->f38 = f38;
	p->texture = t;
	p->position = v;
	p->parent = this;
	return p;
}
}
