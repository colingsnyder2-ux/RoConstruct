// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
class Name;
class Guid { public: static const Name& getLocalScope(); };
class ContentIdX {
public:
	std::string id;
	const Name* scope;
	ContentIdX() : scope(&Guid::getLocalScope()) {}
};
namespace Reflection { class ClassDescriptor; class DescribedBase { public: virtual ~DescribedBase(); protected: const ClassDescriptor* descriptor; }; }
class GuidItemBase { public: virtual ~GuidItemBase(); int g[4]; };
class AbstractFactoryProductBase { public: virtual ~AbstractFactoryProductBase(); };
class Debugable { public: virtual ~Debugable(); int d; };
class __declspec(novtable) SecondBase { public: virtual ~SecondBase(); };
class Instance : public GuidItemBase, public AbstractFactoryProductBase, public Reflection::DescribedBase, public Debugable {
public:
	Instance();
	virtual ~Instance();
	void setName(const std::string& name);
	char instPad[0x8c - 0x28];
};
class CharacterAppearance : public Instance, public SecondBase { protected: CharacterAppearance() {} };
class DescribedShirtGraphic : public CharacterAppearance { public: DescribedShirtGraphic(); };
class ShirtGraphic : public DescribedShirtGraphic {
public:
	ContentIdX graphic;
	ShirtGraphic();
	virtual ~ShirtGraphic();
};
ShirtGraphic::ShirtGraphic()
{
	setName("Shirt Graphic");
}
}
