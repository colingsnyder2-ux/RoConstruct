// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
namespace Reflection {
class ClassDescriptor;
class DescribedBase { public: virtual ~DescribedBase(); protected: const ClassDescriptor* descriptor; };
}
class GuidItemBase { public: virtual ~GuidItemBase(); int g[4]; };
class AbstractFactoryProductBase { public: virtual ~AbstractFactoryProductBase(); };
class Debugable { public: virtual ~Debugable(); int d; };
class SecondBase { public: virtual ~SecondBase(); int s[0xd]; };
class ThirdBase { public: virtual ~ThirdBase(); };
class Instance : public GuidItemBase, public AbstractFactoryProductBase, public Reflection::DescribedBase, public Debugable {
public:
	Instance();
	virtual ~Instance();
	void setName(const std::string&);
	char instPad[0x8c - 0x28];
};
class Hopper : public Instance, public SecondBase, public ThirdBase { public: Hopper(); };
template<class Class, class Base, char** ClassName>
class FactoryProduct : public Base {
protected:
	FactoryProduct() {}
	virtual ~FactoryProduct() {}
};
namespace Reflection {
template<class Class, char** sClassName, class BaseClass>
class __declspec(novtable) Described : public BaseClass {
public:
	Described();
};
}
extern char* sBackpack;
class Backpack : public Reflection::Described<Backpack, &sBackpack, FactoryProduct<Backpack, Hopper, &sBackpack> > {
public:
	Backpack();
};
Backpack::Backpack() { setName("Backpack"); }
}
