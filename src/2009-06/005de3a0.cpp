// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <intrin.h>
namespace boost {
namespace detail {
struct sp_counted_base { virtual void dispose(); long use_count_; long weak_count_; void add_ref_copy() { _InterlockedIncrement(&use_count_); } };
struct shared_count {
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (r.pi_ != 0) r.pi_->add_ref_copy(); }
    ~shared_count();
};
}
template<class T> struct shared_ptr { T* px; detail::shared_count pn; };
namespace _bi {
template<class T> struct value { T t_; };
template<class A1, class A2> struct list2 { A1 a1_; A2 a2_; ~list2(); };
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
namespace RBX { class Instance; }
typedef boost::_bi::bind_t<void, void (*)(std::string, boost::shared_ptr<RBX::Instance>), boost::_bi::list2<boost::_bi::value<std::string>, boost::_bi::value<boost::shared_ptr<RBX::Instance> > > > B;
template boost::function0<void>::function0(B, int);
