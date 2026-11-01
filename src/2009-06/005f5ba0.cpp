// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
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
class GuiTarget { public: virtual ~GuiTarget(); };
class LocalBackpackItem : public Instance, public GuiTarget {
public:
	LocalBackpackItem();
	char itemPad[0xa8 - 0x90];
};
class shared_count { void* pi_; public: shared_count() : pi_(0) {} ~shared_count(); };
template<class T> class shared_ptr { T* px; shared_count pn; public: shared_ptr() : px(0), pn() {} };
class Member { public: Member(); ~Member(); char d[8]; };
class Tool;
class LocalBackpackTool : public LocalBackpackItem {
	shared_ptr<Tool> tool;
	int x, y;
	Member member;
public:
	LocalBackpackTool();
};
LocalBackpackTool::LocalBackpackTool() {}
}
