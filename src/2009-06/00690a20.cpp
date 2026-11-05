// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class GuidItemBase { public: virtual void g0(); char pad[0x10]; };
class Object { public: virtual void o0(); };
class DescribedBase { public: virtual void d0(); int descriptor; };
class Debugable { public: virtual void b0(); char pad[0x68]; };
class Instance : public GuidItemBase, public Object, public DescribedBase, public Debugable {
public:
	Instance();
	virtual ~Instance();
};
class X1 { public: virtual void x1(); char pad[0x1c]; };
class X2 { public: virtual void x2(); char pad[0x74]; };
class X3 { public: virtual void x3(); };
class Base : public Instance, public X1, public X2, public X3 { public: virtual ~Base(); };
class Derived2009 : public Base {
public:
	virtual ~Derived2009();
};
Derived2009::~Derived2009() {}
}
