// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <new>
namespace boost { namespace detail { namespace function {
union function_buffer { void* obj_ptr; double align; char data[8]; };
inline bool has_empty_target(...) { return false; }
struct vtable_base { void (*manager)(); };
template<class F> struct functor_manager { static void manage(); };
template<class F> struct invoker1 { static void invoke(); };
struct basic_vtable1 {
    vtable_base base;
    void (*invoker)();
    template<typename F> bool assign_to(F f, function_buffer& functor) const
    {
        if (!has_empty_target(&f)) {
            new ((void*)&functor.data) F(f);
            return true;
        }
        return false;
    }
};
}}
struct Obj;
struct Fn { void (*f)(Obj*); Obj* o; };
class function1 {
public:
    detail::function::vtable_base* vtable;
    detail::function::function_buffer functor;
    template<typename Functor> void assign_to(Functor f)
    {
        static const detail::function::basic_vtable1 stored_vtable = { { &detail::function::functor_manager<Functor>::manage }, &detail::function::invoker1<Functor>::invoke };
        if (stored_vtable.assign_to(f, functor))
            vtable = (detail::function::vtable_base*)&stored_vtable.base;
        else
            vtable = 0;
    }
};
template void function1::assign_to<Fn>(Fn f);
}
