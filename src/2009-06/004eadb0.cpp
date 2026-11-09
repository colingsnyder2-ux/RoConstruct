// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace boost {
template<class T> class shared_ptr { public: T* px; void* pn; };
namespace _mfi {
template<class R, class T, class A1, class A2> class mf2 {
public:
    typedef R (T::*F)(A1, A2);
    F f_;
    template<class U> R operator()(U& u, A1 a1, A2 a2) const;
};
}
namespace detail { namespace function {
union function_buffer { void* obj_ptr; char data[16]; };
}}
}
namespace RBX {
struct A1x { virtual ~A1x(); };
struct A2x { virtual ~A2x(); };
struct Target : A1x, A2x { void handler(std::string, int); };
}
struct Bound {
    boost::_mfi::mf2<void, RBX::Target, std::string, int> f_;
    boost::shared_ptr<RBX::Target> p_;
    template<class A, class B> struct list2 { A a1_; B a2_; list2(A a, B b) : a1_(a), a2_(b) {} };
    void operator()(std::string& a, int& b) { list2<std::string&, int&> l(a, b); f_(p_, l.a1_, l.a2_); }
};
struct Invoker {
    static void invoke(boost::detail::function::function_buffer& buf, std::string a0, int a1)
    {
        Bound* f = reinterpret_cast<Bound*>(&buf.data);
        (*f)(a0, a1);
    }
};
void (*force)(boost::detail::function::function_buffer&, std::string, int) = &Invoker::invoke;
