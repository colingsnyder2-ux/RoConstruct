// from server: 100% by EspClaude
// roc 2009-06 00692dc0
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class GuidItemBase { public: virtual void g0(); char pad[0x10]; };
class Object { public: virtual void o0(); };
class ClassDescriptor;
class DescribedBase { public: virtual ~DescribedBase() {} const ClassDescriptor* descriptor; };
class Debugable { public: virtual void b0(); char pad[8]; };
class Instance : public GuidItemBase, public Object, public DescribedBase, public Debugable {
public:
	virtual ~Instance();
	char ipad[0x8c - 0x2c];
};
class SecA { public: virtual void a0(); char pad[0x1c]; };
class SecB { public: virtual void b1(); char pad[0x74]; };
class SecC { public: virtual void c0(); };
class BodyMover : public Instance, public SecA, public SecB, public SecC {
public:
	BodyMover(const char* a);
};
class Mover00692dc0;
template<class C, class B>
class FactoryProduct : public B {
public:
	FactoryProduct(const char* a) : B(a) {}
	virtual const char* getClassName() const;
};
extern int counter2009;
class __declspec(novtable) Described2009 : public FactoryProduct<Mover00692dc0, BodyMover> {
public:
	Described2009(const char* a);
	static ClassDescriptor& classDescriptor();
};
Described2009::Described2009(const char* a) : FactoryProduct<Mover00692dc0, BodyMover>(a) { this->descriptor = &classDescriptor(); ++counter2009; }
}
