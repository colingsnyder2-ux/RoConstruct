// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
	virtual ~sp_counted_base();
	virtual void dispose() = 0;
	virtual void destroy();
	void add_ref_copy() { _InterlockedIncrement(&use_count_); }
	void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
	void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
	long use_count_;
	long weak_count_;
};
class shared_count {
public:
	sp_counted_base* pi_;
	shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
	~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr { public: T* px; detail::shared_count pn; };
}
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
class Target_004d3560;
struct Functor { int pmf[2]; boost::shared_ptr<Target_004d3560> obj; };
template void boost::function1<void, int>::assign_to<Functor>(Functor);
