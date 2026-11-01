// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost { namespace detail {
class sp_counted_base {
public:
	virtual ~sp_counted_base();
	virtual void dispose() = 0;
	virtual void destroy();
	void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
	long use_count_;
	long weak_count_;
};
class weak_count {
public:
	sp_counted_base* pi_;
	~weak_count() { if (pi_ != 0) pi_->weak_release(); }
};
}
template<class T> class weak_ptr { public: T* px; detail::weak_count pn; };
}
namespace RBX { class Instance; namespace Network { class Player;
struct WeakPair2009 {
	boost::weak_ptr<Player> a;
	boost::weak_ptr<Instance> b;
	~WeakPair2009();
};
WeakPair2009::~WeakPair2009() {}
}}
