// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace boost {
template<class T> class shared_ptr { public: T* px; void* pn; };
template<class T> class weak_ptr { public: T* px; void* pn; };
namespace detail { namespace function {
struct X;
union function_buffer {
    void* obj_ptr;
    struct type_t { const void* type; bool c; bool v; } type;
    void (*func_ptr)();
    struct bound_memfunc_ptr_t { void (X::*memfunc_ptr)(int); void* obj_ptr; } bound_memfunc_ptr;
    char data;
    double align_;
};
struct vtable_base { void* manager; };
}}
class function_base {
public:
    function_base() : vtable(0) {}
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
};
template<class R> class function0 : public function_base {
public:
    template<class Functor> function0(Functor f, int = 0);
};
template<class Sig> class function;
template<class R> class function<R()> : public function0<R> {
    typedef function0<R> base_type;
public:
    template<class Functor> function(Functor f, int = 0) : base_type(f) {}
};
namespace _bi {
template<class T> class value { public: T t_; };
template<class A1> struct storage1 { A1 a1_; };
template<class A1, class A2> struct storage2 : public storage1<A1> { A2 a2_; storage2(const storage2&); ~storage2(); };
template<class A1, class A2, class A3> struct storage3 : public storage2<A1, A2> { A3 a3_; storage3(const storage3&); ~storage3(); };
template<class A1, class A2, class A3, class A4> struct storage4 : public storage3<A1, A2, A3> { A4 a4_; };
template<class A1, class A2, class A3, class A4> class list4 : private storage4<A1, A2, A3, A4> {};
template<class R, class F, class L> class bind_t { public: F f_; L l_; };
}
}
namespace RBX { class Instance; namespace Network { class Player; } }
typedef boost::_bi::bind_t<void, void (*)(boost::weak_ptr<RBX::Instance>, boost::shared_ptr<RBX::Network::Player>, std::string, bool),
    boost::_bi::list4<boost::_bi::value<boost::weak_ptr<RBX::Instance> >, boost::_bi::value<boost::shared_ptr<RBX::Network::Player> >,
    boost::_bi::value<std::string>, boost::_bi::value<bool> > > BindT;
template boost::function<void()>::function(BindT, int);
