// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#define _DLL
#include <string>
namespace RBX {
class Adorn;
class Name { public: int id; std::string str; const std::string& toString() const { return str; } };
class Verb { public: virtual ~Verb(); const Name& name; const Name& getName() const { return name; } };
template<class T> class GuidItem { public: virtual ~GuidItem(); char guidPad[0xc]; };
class Object { public: virtual ~Object(); };
class DescribedBase { public: virtual ~DescribedBase(); int a, b; };
class Debugable { public: virtual void dump(); };
template<int N> class Notifier { public: virtual ~Notifier(); char pad[0x1c]; };
class Instance : public GuidItem<Instance>, public Object, public DescribedBase, public Debugable,
	public Notifier<0>, public Notifier<1>, public Notifier<2>, public Notifier<3>, public Notifier<4>, public Notifier<5>
{
	char ipad[0x130 - 0xe4];
public:
	virtual ~Instance();
	virtual void setName(const std::string& name);
};
class GuiTarget { public: virtual ~GuiTarget(); char gpad[0x8]; };
class GuiItem : public Instance, public GuiTarget { public: virtual ~GuiItem(); };
class Widget : public GuiItem { public: virtual ~Widget(); char wpad[0x10]; };
class VerbWidget : public Widget { public: VerbWidget(Verb* verb); virtual ~VerbWidget(); };
class GuiDrawImage { public: GuiDrawImage(Adorn* adorn, const std::string& image); ~GuiDrawImage(); char dpad[0x20]; };
class ImageButton : public VerbWidget
{
protected:
	GuiDrawImage guiImageDraw;
public:
	ImageButton(Adorn* adorn, Verb* verb, const std::string& name);
	virtual void render2d(Adorn* adorn);
};
ImageButton::ImageButton(Adorn* adorn, Verb* verb, const std::string& name)
	: VerbWidget(verb),
	guiImageDraw(adorn, verb->getName().toString())
{
	setName(name);
}
}
