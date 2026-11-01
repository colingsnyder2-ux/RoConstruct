// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
namespace boost {
namespace mpl { template<bool C> struct bool_ {}; typedef bool_<false> false_; }
namespace detail { namespace function {
union function_buffer { void* obj_ptr; char data[8]; };
struct List2 { std::string a1_; int a2_; };
struct Bound { void (*f_)(std::string, int); List2 l_; };
template<class R> struct basic_vtable0 {
    template<class F> void assign_functor(F f, function_buffer& functor, mpl::false_) {
        functor.obj_ptr = new F(f);
    }
};
template void basic_vtable0<void>::assign_functor<Bound>(Bound, function_buffer&, mpl::false_);
}}}
