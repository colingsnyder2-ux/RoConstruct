// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection {
class ClassDescriptor;
class DescribedBase { public: virtual ~DescribedBase(); protected: const ClassDescriptor* descriptor; };
}
template<class T> struct ExeCounter { static int count; };
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
class Widget : public Instance, public GuiTarget {
public:
	Widget();
	virtual ~Widget();
	char widgetPad[0xa4 - 0x90];
};
class LocalBackpackItem : public Widget {
	float size;
public:
	LocalBackpackItem(float s) : size(s) {}

};
template<class T, class Base, const char* sName>
class FactoryProduct : public Base {
public:
	static Reflection::ClassDescriptor& classDescriptor();
	template<class U> FactoryProduct(U arg0) : Base(arg0) {}
	virtual ~FactoryProduct() {}
};
extern const char sLocalBackpackTool[];
class __declspec(novtable) LocalBackpackTool : public FactoryProduct<LocalBackpackTool, LocalBackpackItem, sLocalBackpackTool> {
public:
	LocalBackpackTool(float s);
};
LocalBackpackTool::LocalBackpackTool(float s) : FactoryProduct<LocalBackpackTool, LocalBackpackItem, sLocalBackpackTool>(s)
{
	this->descriptor = &classDescriptor();
	++ExeCounter<LocalBackpackTool>::count;
}
}
