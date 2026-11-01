// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <string>
namespace boost {
namespace detail {
class sp_counted_base {
public:
	virtual ~sp_counted_base();
	virtual void dispose() = 0;
	virtual void destroy();
	long use_count_;
	long weak_count_;
	void add_ref_copy() { _InterlockedIncrement(&use_count_); }
	void weak_add_ref() { _InterlockedIncrement(&weak_count_); }
	void release();
	void weak_release();
};
class shared_count {
	sp_counted_base* pi_;
public:
	shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
	~shared_count();
};
class weak_count {
	sp_counted_base* pi_;
public:
	weak_count(const weak_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->weak_add_ref(); }
	~weak_count();
};
}
template<class T> class shared_ptr { public: T* px; detail::shared_count pn; };
template<class T> class weak_ptr { public: T* px; detail::weak_count pn; };
template<class T> struct type {};
namespace _bi {
template<class T> struct value { T t_; T& get() { return t_; } };
template<class A1, class A2, class A3, class A4> struct list4 {
	A1 a1_; A2 a2_; A3 a3_; A4 a4_;
	template<class F, class A> void operator()(type<void>, F& f, A& a, int)
	{
		f(a1_.get(), a2_.get(), a3_.get(), a4_.get());
	}
};
struct list0 {};
}
}
namespace RBX { class Instance; class Player; }
typedef void (*Fn)(boost::weak_ptr<RBX::Player>, boost::shared_ptr<RBX::Instance>, std::string, bool);
template void boost::_bi::list4<boost::_bi::value<boost::weak_ptr<RBX::Player> >, boost::_bi::value<boost::shared_ptr<RBX::Instance> >, boost::_bi::value<std::string>, boost::_bi::value<bool> >::operator()<Fn, boost::_bi::list0>(boost::type<void>, Fn&, boost::_bi::list0&, int);
