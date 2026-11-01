// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
namespace Reflection { class DescribedBase { public: virtual ~DescribedBase(); protected: const void* descriptor; }; }
class GuidItemBase { public: virtual ~GuidItemBase(); int g[4]; };
class AbstractFactoryProductBase { public: virtual ~AbstractFactoryProductBase(); };
class Debugable { public: virtual ~Debugable(); int d; };
class Instance : public GuidItemBase, public AbstractFactoryProductBase, public Reflection::DescribedBase, public Debugable {
public:
	Instance();
	virtual ~Instance();
	char instPad[0x8c - 0x28];
};
namespace Reflection { namespace Metadata {
class DescribedItem : public Instance { public: DescribedItem(); };
class Item : public DescribedItem {
	bool a, b, c;
	std::string s;
public:
	Item();
};
Item::Item() : a(true), b(false), c(false) {}
} }
}
