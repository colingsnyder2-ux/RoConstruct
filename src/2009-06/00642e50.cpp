// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace bb { template<class T> struct value { T t_; value(T t) : t_(t) {} }; template<class A> struct list1 { A a1_; list1(A a) : a1_(a) {} };
template<class R, class F, class L> struct bind_t { F f_; L l_; bind_t(F f, const L& l) : f_(f), l_(l) {} };
template<class R, class B1, class A1> inline bind_t<R, R (*)(B1), list1<value<A1> > > bind(R (*f)(B1), A1 a1) { return bind_t<R, R (*)(B1), list1<value<A1> > >(f, list1<value<A1> >(value<A1>(a1))); } }
typedef bb::bind_t<void, void (*)(unsigned int), bb::list1<bb::value<unsigned int> > > Bound;
void onColorChanged(unsigned int);
struct Listener { void raise(Bound); };
struct PackedColor { unsigned int value; };
struct ColorSetting { PackedColor color; Listener* listener; };
extern ColorSetting colorSetting;
namespace RBX {
class Instance;
class UIEvent;
class Filter;
extern Filter exeFilter;
class PartInstance { public: char pad[0x120]; PackedColor color; PackedColor getColor() const { return color; } };
class SoundService { public: void playSound(int); };
SoundService* findSoundService(Instance* context);
class MouseCommand {
public:
    virtual ~MouseCommand();
    char pad[0x14];
    Instance* workspace;
    PartInstance* getPart(const UIEvent& event, Instance* ignore, Filter* filter);
};
class DropperTool : public MouseCommand {
public:
    MouseCommand* onMouseDown(const UIEvent& event);
};
MouseCommand* DropperTool::onMouseDown(const UIEvent& event)
{
    if (PartInstance* part = getPart(event, 0, &exeFilter)) {
        unsigned int value = part->getColor().value;
        if (colorSetting.color.value != value) {
            Listener* listener = colorSetting.listener;
            colorSetting.color.value = value;
            Bound b = bb::bind(&onColorChanged, value);
            if (listener)
                listener->raise(b);
        }
        findSoundService(workspace)->playSound(4);
    }
    return 0;
}
}
