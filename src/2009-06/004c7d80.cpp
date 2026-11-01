// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
namespace mpl { template<bool C> struct bool_ {}; typedef bool_<false> false_; }
namespace detail { namespace function {
union function_buffer { void* obj_ptr; char data[8]; };
struct Member { char d[0x24]; Member(const Member&); ~Member(); };
struct List { Member a1_; };
struct Bound { void* f_; List l_; };
template<class R> struct basic_vtable0 {
    template<class FunctionObj> void assign_functor(FunctionObj f, function_buffer& functor, mpl::false_) {
        functor.obj_ptr = new FunctionObj(f);
    }
};
template void basic_vtable0<void>::assign_functor<Bound>(Bound, function_buffer&, mpl::false_);
}}}
