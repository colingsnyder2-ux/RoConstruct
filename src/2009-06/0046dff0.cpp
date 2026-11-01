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
	long use_count_;
	long weak_count_;
};
class shared_count {
public:
	sp_counted_base* pi_;
	shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
	~shared_count();
};
}
template<class T> class shared_ptr {
public:
	T* px;
	detail::shared_count pn;
	typedef T* shared_ptr::*unspecified_bool_type;
	operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
	void reset();
};
}
namespace RBX {
namespace Security {
class Impersonator {
	void* previous;
public:
	Impersonator(int identity);
	~Impersonator();
};
}
class Item;
class Owner {
public:
	char pad[0x1c];
	boost::shared_ptr<Item> item;
	boost::shared_ptr<Item> other;
	static void release(boost::shared_ptr<Item> item);
	void stop();
};
void Owner::stop()
{
	if (item) {
		Security::Impersonator impersonate(4);
		other.reset();
		release(item);
		item.reset();
	}
}
}
