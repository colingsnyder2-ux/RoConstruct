// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
inline long atomic_decrement(long* pw) { return _InterlockedDecrement(pw); }
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void weak_release() { if (atomic_decrement(&weak_count_) == 0) destroy(); }
    void release() { if (atomic_decrement(&use_count_) == 0) { dispose(); weak_release(); } }
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
}
class A; class B;
struct B1 { int a; }; struct B2 { int b; };
class C : public B1, public B2 { public: void m(int); };
template<class R, class T, class A1> class mf1 {
    typedef R (T::*F)(A1);
    F f_;
public:
    R operator()(T* p, A1 a1) const { (p->*f_)(a1); }
};
template<class T> struct value { T t_; T& get() { return t_; } };
template<class A1, class A2> struct list2 {
    A1 a1_; A2 a2_;
    template<class F, class L> void operator()(F& f, L&) { f(a1_.get(), a2_.get()); }
};
template<class F, class L> struct bind_t {
    F f_; L l_;
    template<class X0, class X1> void operator()(X0& x0, X1& x1) { int dummy[2]; l_(f_, dummy); }
};
typedef bind_t<mf1<void, C, int>, list2<value<C*>, value<int> > > BT;
union function_buffer { void* obj_ptr; char data[16]; };
template<class F, class T0, class T1> struct void_function_obj_invoker2 {
    static void invoke(function_buffer& buf, T0 a0, T1 a1) {
        F* f = reinterpret_cast<F*>(&buf.data);
        (*f)(a0, a1);
    }
};
template struct void_function_obj_invoker2<BT, boost::shared_ptr<A>, boost::shared_ptr<B> >;
