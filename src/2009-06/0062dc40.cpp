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
	long use_count_;
	long weak_count_;
	void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
	void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
class shared_count {
	sp_counted_base* pi_;
public:
	~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr { public: T* px; detail::shared_count pn; };
}
namespace RBX {
class RootInstance {
public:
	virtual ~RootInstance();
	char pad[0x48];
};
class Thing;
class __declspec(novtable) Derived : public RootInstance {
public:
	boost::shared_ptr<Thing> thing;
	~Derived();
};
Derived::~Derived() {}
}
