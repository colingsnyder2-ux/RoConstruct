// from server: 99% by EspClaude
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
	void release() {
		if (_InterlockedDecrement(&use_count_) == 0) {
			dispose();
			if (_InterlockedDecrement(&weak_count_) == 0)
				destroy();
		}
	}
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
};
}
namespace RBX {
class Instance;
class Base {
public:
	Base(int a, std::string name, boost::shared_ptr<Instance> p);
};
class Derived : public Base {
public:
	Derived(int a, std::string name, boost::shared_ptr<Instance> p);
};
Derived::Derived(int a, std::string name, boost::shared_ptr<Instance> p) : Base(a, name, p)
{
}
}
