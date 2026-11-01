// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
class GuidItemBase { public: virtual void g0(); char pad[0x10]; };
class Object { public: virtual void o0(); };
class ClassDescriptor;
class DescribedBase { public: virtual ~DescribedBase() {} const ClassDescriptor* descriptor; };
class Debugable { public: virtual void b0(); char pad[8]; };
class Instance : public GuidItemBase, public Object, public DescribedBase, public Debugable {
public:
	Instance();
	virtual ~Instance();
	char ipad[0x8c - 0x2c];
};
class GuiTarget2009 { public: virtual void t0(); char pad[0x18 - 4]; };
class Widget2009 : public Instance, public GuiTarget2009 { public: Widget2009(); virtual ~Widget2009(); };
class BackpackItemBase2009 : public Widget2009 { public: BackpackItemBase2009(); virtual ~BackpackItemBase2009(); };
struct Member38 { Member38(); ~Member38(); char pad[0x38]; };
struct Thing2009;
const Thing2009* getThing2009();
struct Ref2009 {
	std::string s;
	const Thing2009* p;
	Ref2009() : p(getThing2009()) {}
};
class BackpackItem : public BackpackItemBase2009 {
public:
	BackpackItem();
	virtual void v0();
	Member38 m;
	Ref2009 r;
};
BackpackItem::BackpackItem() {}
}
