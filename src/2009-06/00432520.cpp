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
template<class T> class shared_ptr {
public:
	T* px;
	detail::shared_count pn;
	T* get() const { return px; }
};
template<class T> T* get_pointer(const shared_ptr<T>& p) { return p.get(); }
namespace _mfi {
template<class R, class T, class A1> class mf1 {
	typedef R (T::*F)(A1);
	F f_;
	template<class U, class B1> R call(U& u, const void*, B1& b1) const { return (get_pointer(u)->*f_)(b1); }
public:
	template<class U> R operator()(U& u, A1 a1) const { return call(u, &u, a1); }
};
}
namespace program_options {
class option_description;
class options_description { public: void add(shared_ptr<option_description> d); };
}
template void _mfi::mf1<void, program_options::options_description, shared_ptr<program_options::option_description> >::operator()(shared_ptr<program_options::options_description>&, shared_ptr<program_options::option_description>) const;
}
