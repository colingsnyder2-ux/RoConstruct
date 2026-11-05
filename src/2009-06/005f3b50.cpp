// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
namespace detail { namespace function {
union function_buffer {
	void* obj_ptr;
	void (*func_ptr)();
	double align_;
	char data[16];
};
struct vtable_base { void (*manager)(); };
template<class R, class T0> struct basic_vtable1 {
	vtable_base base;
	void (*invoker)();
	template<class F> bool assign_to(F f, function_buffer& functor);
};
}}
class function_base {
public:
	detail::function::vtable_base* vtable;
	mutable detail::function::function_buffer functor;
};
template<class R, class T0> class function1 : public function_base {
	typedef detail::function::basic_vtable1<R, T0> vtable_type;
public:
	template<class Functor> void assign_to(Functor f);
};
template<class R, class T0> template<class Functor> void function1<R, T0>::assign_to(Functor f)
{
	static vtable_type stored_vtable;
	if (stored_vtable.assign_to(f, functor))
		vtable = &stored_vtable.base;
	else
		vtable = 0;
}
}
struct Functor { int a[6]; };
template void boost::function1<void, int>::assign_to<Functor>(Functor);
