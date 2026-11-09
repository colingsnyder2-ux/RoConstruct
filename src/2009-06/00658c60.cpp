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
class DescribedBase { public: virtual ~DescribedBase(); protected: const ClassDescriptor* descriptor; };
}
class GuidItemBase { public: virtual ~GuidItemBase(); int g[4]; };
class AbstractFactoryProductBase { public: virtual ~AbstractFactoryProductBase(); };
class Debugable { public: virtual ~Debugable(); int d; };
class Instance : public GuidItemBase, public AbstractFactoryProductBase, public Reflection::DescribedBase, public Debugable {
public:
	Instance();
	virtual ~Instance();
};
template<class Class, class Base, char** ClassName>
class FactoryProduct : public Base {
protected:
	FactoryProduct() {}
	virtual ~FactoryProduct() {}
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
extern char* sControllerService;
class ControllerService;
template class Reflection::Described<ControllerService, &sControllerService, FactoryProduct<ControllerService, Instance, &sControllerService> >;
}
