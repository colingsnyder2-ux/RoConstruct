// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
template<class T> class Array {
public:
	T* data;
	int num;
	int numAllocated;
	void append(const T& v);
	int size() const { return num; }
	T& operator[](int n) { return data[n]; }
};
}
class Pad20 { public: virtual void p0(); char pad[0x1c]; };
class Base20 { public: virtual void q0(); };
class Primitive2009 : public Pad20, public Base20 {
public:
	virtual void v1(); virtual void v2(); virtual void v3();
	virtual int isAnchored();
	virtual int getKind();
};
class Pad8 { public: virtual void r0(); int x; };
class Base8 { public: virtual void s0(); };
class Assembly2009 : public Pad8, public Base8 {
public:
	char pad[0x20];
	Base20* prim;
	Primitive2009* getPrimitive() const { return static_cast<Primitive2009*>(prim); }
};
class Clump2009 {
public:
	char pad[0xc];
	G3D::Array<Clump2009*> children;
	int y;
	Base8* assembly;
	Assembly2009* getAssembly() const { return static_cast<Assembly2009*>(assembly); }
	void collect(G3D::Array<const Primitive2009*>& out);
};
void Clump2009::collect(G3D::Array<const Primitive2009*>& out)
{
	Primitive2009* p = getAssembly()->getPrimitive();
	if (!p->isAnchored() && p->getKind() == 3) {
		const Primitive2009* q = p;
		out.append(q);
	}
	for (int i = 0; i < children.size(); ++i)
		children[i]->collect(out);
}
