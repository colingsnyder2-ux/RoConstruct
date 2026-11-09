// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX { namespace Network { class Players; } }
struct Arg48 { double d; char pad[0x40]; Arg48(const Arg48&); ~Arg48(); };
namespace boost {
namespace _mfi { template<class R, class T, class A1, class A2> struct mf2 { R (T::*f_)(A1, A2); }; }
namespace _bi {
template<class T> struct value { T t_; };
template<class A1, class A2, class A3> struct list3 { A1 a1_; A2 a2_; A3 a3_; };
template<class R, class F, class L> struct bind_t { F f_; L l_; };
}
namespace detail { namespace function {
union function_buffer { void* obj_ptr; char data[8]; double d; };
struct vtable_base { void* manager; };
}}
template<class R> class function0 {
public:
    detail::function::vtable_base* vtable;
    detail::function::function_buffer functor;
    template<class Functor> function0(Functor f, int = 0) : vtable(0) { this->assign_to(f); }
    template<class Functor> void assign_to(Functor f);
};
}
struct Pair8 { int a, b; };
struct L2 { Arg48 a1_; int a2_; };
typedef boost::_bi::bind_t<void, Pair8, L2> B;
template boost::function0<void>::function0(B, int);
