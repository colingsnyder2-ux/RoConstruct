// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection {
class ClassDescriptor;
template<class Class> class ClassRegistrar {
	int x;
public:
	ClassRegistrar(int);
	void dummy() { x++; }
	static ClassRegistrar registrar;
};
}
class GuidItemBase { public: virtual ~GuidItemBase(); int g[4]; };
class AbstractFactoryProductBase { public: virtual ~AbstractFactoryProductBase(); };
class DescribedBase { public: virtual ~DescribedBase(); protected: const Reflection::ClassDescriptor* descriptor; };
class Debugable { public: virtual ~Debugable(); int d; };
class Instance : public GuidItemBase, public AbstractFactoryProductBase, public DescribedBase, public Debugable {
public:
	Instance();
	virtual ~Instance();
	char instPad[0x8c - 0x28];
};
class __declspec(novtable) VB { public: virtual void vf(); };
class A { public: virtual void a(); };
class Mid : public Instance, public A, public virtual VB { public: int m[2]; };
class B1 { public: virtual void b1(); int m[2]; };
class B2 { public: virtual void b2(); int m[3]; };
class B3 : public virtual VB { public: virtual void b3(); };
class Base : public Mid, public B1, public B2, public B3 {
public:
	Base();
	virtual ~Base();
	virtual void vf();
	char pad[0x238 - 0xc0];
};
template<class Class, class B, char** ClassName>
class FactoryProduct : public B {
protected:
	FactoryProduct() {}
};
namespace Reflection {
template<class Class, char** sClassName, class BaseClass>
class __declspec(novtable) Described : public BaseClass {
	void forceRegistration() { ClassRegistrar<Class>::registrar.dummy(); }
public:
	static ClassDescriptor& classDescriptor();
	Described() {
		this->descriptor = &classDescriptor();
		forceRegistration();
	}
};
}
extern char* sObj;
class Obj : public Reflection::Described<Obj, &sObj, FactoryProduct<Obj, Base, &sObj> > {
public:
	Obj();
	virtual ~Obj();
};
Obj::Obj() {}
}
