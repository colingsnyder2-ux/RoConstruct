// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
template<class T> class shared_ptr {
public:
    T* px; void* pn;
    template<class Y, class D> shared_ptr(Y* p, D d);
    ~shared_ptr();
};
}
namespace RBX {
struct B0 { virtual ~B0(); char p0[0x10]; };
struct B1 { virtual void f1(); };
struct B2 { virtual void f2(); int p2; };
struct B3 { virtual void f3(); char p3[0x68]; };
class Instance : public B0, public B1, public B2, public B3 { public: virtual ~Instance(); };
struct GuiTarget { virtual void g(); };
class LocalBackpackItem : public Instance, public GuiTarget {
public:
    LocalBackpackItem(float f);
    char pi[0xa8 - 0x90];
};
class LocalBackpackSwitcher : public LocalBackpackItem {
public:
    LocalBackpackSwitcher(float f) : LocalBackpackItem(f) {}
    virtual ~LocalBackpackSwitcher();
};
template<class Base> class Creatable {
public:
    class Deleter { public: void operator()(Base* p); };
    template<class T, typename Arg0> static boost::shared_ptr<T> create(Arg0 arg0)
    {
        return boost::shared_ptr<T>(new T(arg0), Deleter());
    }
};
template boost::shared_ptr<LocalBackpackSwitcher> Creatable<Instance>::create<LocalBackpackSwitcher, float>(float);
}
