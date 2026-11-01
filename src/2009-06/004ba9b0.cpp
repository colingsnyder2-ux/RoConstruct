// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
namespace detail { namespace function {
union function_buffer { void* obj_ptr; char data[8]; };
struct function_obj_tag {};
struct Member { char d[0x2c]; Member(const Member&); ~Member(); };
struct List { Member a1_; bool a2_; };
struct Bound { void* f_; List l_; };
template<class R> struct basic_vtable0 {
    template<class F> bool assign_to(F f, function_buffer& functor) {
        return assign_to(f, functor, function_obj_tag());
    }
    template<class F> bool assign_to(F f, function_buffer& functor, function_obj_tag);
};
template bool basic_vtable0<void>::assign_to<Bound>(Bound, function_buffer&);
}}}
