// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
namespace detail { namespace function {
union function_buffer { void* obj_ptr; double align_; char data[16]; };
template<class R> struct basic_vtable0 {
	void* manager;
	void* invoker;
	template<class F> bool assign_to(F f, function_buffer& functor);
};
}}
class function_base {
public:
	void* vtable;
	mutable detail::function::function_buffer functor;
};
template<class R> class function0 : public function_base {
public:
	typedef detail::function::basic_vtable0<R> vtable_type;
	template<class F> void assign_to(F f)
	{
		static vtable_type stored_vtable = { 0, 0 };
		if (stored_vtable.assign_to(f, this->functor))
			this->vtable = &stored_vtable;
		else
			this->vtable = 0;
	}
};
}
struct X { double d; char pad[0x40]; X(const X&); ~X(); };
struct Y { X c; int d; };
struct F { int a; int b; Y y; };
template void boost::function0<void>::assign_to<F>(F);
