// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); if (_InterlockedDecrement(&weak_count_) == 0) destroy(); } }
    long use_count_;
    long weak_count_;
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
namespace detail { namespace function {
union function_buffer { void* obj_ptr; double d; char data[0x18]; };
}}
}
struct Tag {};
template<class A1, class A2> struct args2 {
    const A1* a1; const A2* a2;
    args2(const A1& x, const A2& y) : a1(&x), a2(&y) {}
};
class Thing;
template<class A1, class A2> class Signal2;
template<class A1, class A2> class SignalImpl {
public:
    void call(Tag t, Signal2<A1, A2>* owner, args2<A1, A2>* args, int n);
};
template<class A1, class A2> class Signal2 {
public:
    int hdr;
    SignalImpl<A1, A2> impl;
    void operator()(const A1& a, const A2& b) { args2<A1, A2> args(a, b); impl.call(Tag(), this, &args, 0); }
};
template<class F, class R, class T0, class T1> struct function_obj_invoker2 {
    static R invoke(boost::detail::function::function_buffer& function_obj_ptr, T0 a0, T1 a1)
    {
        F* f = reinterpret_cast<F*>(function_obj_ptr.obj_ptr);
        return (*f)(a0, a1);
    }
};
typedef Signal2<int, boost::shared_ptr<Thing> > Sig;
template struct function_obj_invoker2<Sig, void, int, boost::shared_ptr<Thing> >;
