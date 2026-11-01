// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <new>
namespace boost {
namespace detail { namespace function {
union function_buffer {
	void* obj_ptr;
	void (*func_ptr)();
	double align_;
	char data[16];
};
struct vtable_base { void (*manager)(); };
inline bool has_empty_target(...) { return false; }
template<class F> struct functor_manager { static void manage(); };
template<class F> struct invoker0 { static void invoke(); };
template<class R> struct basic_vtable0 {
	vtable_base base;
	void (*invoker)();
	template<class F> bool assign_to(F f, function_buffer& functor)
	{
		if (!has_empty_target(&f)) {
			new ((void*)&functor.data) F(f);
			return true;
		}
		return false;
	}
};
}}
class function_base {
public:
	detail::function::vtable_base* vtable;
	mutable detail::function::function_buffer functor;
};
template<class R> class function0 : public function_base {
	typedef detail::function::basic_vtable0<R> vtable_type;
public:
	template<class Functor> void assign_to(Functor f);
};
template<class R> template<class Functor> void function0<R>::assign_to(Functor f)
{
	static vtable_type stored_vtable = { { (void(*)())&detail::function::functor_manager<Functor>::manage }, &detail::function::invoker0<Functor>::invoke };
	if (stored_vtable.assign_to(f, functor))
		vtable = &stored_vtable.base;
	else
		vtable = 0;
}
}
struct Functor { void (*f)(int); int a; };
template void boost::function0<void>::assign_to<Functor>(Functor);
