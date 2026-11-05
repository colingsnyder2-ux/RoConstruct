// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost { namespace detail {
class sp_counted_base {
public:
	virtual ~sp_counted_base();
	long use_count_;
	long weak_count_;
	void add_ref_copy() { _InterlockedIncrement(&use_count_); }
	void release();
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
class Sink {
public:
	void operator()(boost::shared_ptr<Instance> p);
};
class Holder {
public:
	char pad[0x80];
	Sink sink;
	void fire(const boost::shared_ptr<Instance>& p);
};
void Holder::fire(const boost::shared_ptr<Instance>& p)
{
	sink(p);
}
}
