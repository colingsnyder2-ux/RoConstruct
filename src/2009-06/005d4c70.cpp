// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Instance;
class __multiple_inheritance Selection;
struct Connection { void* px; void* pn; Connection& operator=(const Connection&); ~Connection(); };
struct Base1 { virtual void a(); };
struct Base2 { virtual void b(); };
struct mf1 { void (Selection::*f_)(Instance*); explicit mf1(void (Selection::*f)(Instance*)) : f_(f) {} };
template<class T> struct value { T t_; value(const T& t) : t_(t) {} };
struct list2 { value<Selection*> a1_; value<Instance*> a2_; list2(value<Selection*> a1, value<Instance*> a2) : a1_(a1), a2_(a2) {} };
struct BindT { mf1 f_; list2 l_; BindT(mf1 f, const list2& l) : f_(f), l_(l) {} };
inline BindT bind(void (Selection::*f)(Instance*), Selection* s, Instance* i) { return BindT(mf1(f), list2(s, i)); }
struct Signal { Connection connect(BindT slot); };
class Instance { public: char pad[0x84]; Signal ancestryChangedSignal; };
template<class K, class V> struct Map { V& operator[](const K& k); };
class Selection : public Base1, public Base2 {
public:
    char pad[0xa4];
    Map<Instance*, Connection> connections;
    void onAncestryChanged(Instance* instance);
    void connectInstance(Instance* instance);
};
void Selection::connectInstance(Instance* instance)
{
    connections[instance] = instance->ancestryChangedSignal.connect(bind(&Selection::onAncestryChanged, this, instance));
}
}
