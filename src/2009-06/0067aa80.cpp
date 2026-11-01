// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <intrin.h>
namespace boost {
namespace detail {
inline long atomic_increment(long* pw) { return _InterlockedIncrement(pw); }
inline long atomic_decrement(long* pw) { return _InterlockedDecrement(pw); }
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void weak_add_ref() { atomic_increment(&weak_count_); }
    void weak_release() { if (atomic_decrement(&weak_count_) == 0) destroy(); }
    void release() { if (atomic_decrement(&use_count_) == 0) { dispose(); weak_release(); } }
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
class weak_count {
public:
    sp_counted_base* pi_;
    weak_count& operator=(shared_count const& r);
    ~weak_count() { if (pi_ != 0) pi_->weak_release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
template<class T> class weak_ptr {
public:
    T* px;
    detail::weak_count pn;
    template<class Y> weak_ptr& operator=(shared_ptr<Y> const& r) { px = r.px; pn = r.pn; return *this; }
};
}
namespace RBX {
class Instance { public: virtual ~Instance(); };
class Sky : public Instance {};
template<class T> boost::shared_ptr<T> shared_from(T* p);
struct Slot;
template<class T> struct value { T t_; value(T const& t) : t_(t) {} };
struct arg1 {};
template<class A1> struct storage1 { };
template<class A1, class A2> struct storage2 : public storage1<A1> { A2 a2_; storage2(A1 a1, A2 a2) : storage1<A1>(), a2_(a2) {} };
template<class A1, class A2> struct list2 : private storage2<A1, A2> { list2(A1 a1, A2 a2) : storage2<A1, A2>(a1, a2) {} };
template<class F, class L> struct bind_t { F f_; L l_; bind_t(F f, L const& l) : f_(f), l_(l) {} };
template<class B1> inline bind_t<void (*)(Slot*, B1), list2<arg1, value<B1> > > bind(void (*f)(Slot*, B1), arg1 a1, B1 b1)
{ typedef list2<arg1, value<B1> > L; return bind_t<void (*)(Slot*, B1), L>(f, L(a1, b1)); }

class SlotList {
public:
    template<class F> void visit(F f);
};
void callSlot(Slot* s, bool a);
class Signal {
public:
    SlotList* impl;
    void operator()(bool a1) { bind_t<void (*)(Slot*, bool), list2<arg1, value<bool> > > b = bind(&callSlot, arg1(), a1); if (impl) impl->visit(b); }
};
}
namespace G3D {
class Color3 {
public:
    float r, g, b;
    Color3(const Color3& o) : r(o.r), g(o.g), b(o.b) {}
    Color3& operator=(const Color3& o) { r = o.r; g = o.g; b = o.b; return *this; }
    bool operator==(const Color3& o) const { return r == o.r && g == o.g && b == o.b; }
    bool operator!=(const Color3& o) const { return r != o.r || g != o.g || b != o.b; }
};
}
namespace RBX {
namespace Reflection { class PropertyDescriptor; }
extern Reflection::PropertyDescriptor prop_ShadowColor;
class Lighting {
public:
    char pad[0x1ec];
    G3D::Color3 shadowColor;
    char pad2[0x234 - 0x1f8];
    Signal skyChanged;
    void raisePropertyChanged(const Reflection::PropertyDescriptor& d);
    void setShadowColor(G3D::Color3 value);
};
void Lighting::setShadowColor(G3D::Color3 value)
{
    if (value != shadowColor) {
        shadowColor = value;
        raisePropertyChanged(prop_ShadowColor);
        skyChanged(false);
    }
}
}
