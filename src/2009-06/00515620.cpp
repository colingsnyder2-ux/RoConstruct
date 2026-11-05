// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
namespace G3D {
class Color3 { public: float r, g, b; };
class AtomicInt32 { public: volatile long v; long decrement() { return InterlockedDecrement(&v); } };
class ReferenceCountedObject {
public:
	AtomicInt32 ReferenceCountedObject_refCount;
	void* ReferenceCountedObject_weakPointer;
	void ReferenceCountedObject_zeroWeakPointers();
	virtual ~ReferenceCountedObject() {}
};
template<class T> class ReferenceCountedPointer {
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
public:
	ReferenceCountedPointer() : m_pointer(0) {}
	ReferenceCountedPointer(T* p) : m_pointer(0) { if (p) { m_pointer = p; InterlockedIncrement(&p->ReferenceCountedObject_refCount.v); } }
	ReferenceCountedPointer(const ReferenceCountedPointer& o);
	~ReferenceCountedPointer() { zeroPointer(); }
	T* operator->() const { return m_pointer; }
};
}
namespace RBX {
namespace Render {
class TextureProxy : public G3D::ReferenceCountedObject {
public:
	virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
	virtual G3D::ReferenceCountedPointer<TextureProxy> shade(const G3D::Color3& tint, const G3D::ReferenceCountedPointer<TextureProxy>& other);
};
}
namespace View {
class MaterialFactory {
	void* pad;
	G3D::ReferenceCountedPointer<Render::TextureProxy> surfacesTexture;
	G3D::ReferenceCountedPointer<Render::TextureProxy> getSurfacesTexture(G3D::Color3 tint);
};
G3D::ReferenceCountedPointer<Render::TextureProxy> MaterialFactory::getSurfacesTexture(G3D::Color3 tint)
{
	return surfacesTexture->shade(tint, 0);
}
}
}
