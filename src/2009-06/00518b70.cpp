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
	void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
	void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
	long use_count_;
	long weak_count_;
};
class shared_count {
public:
	sp_counted_base* pi_;
	~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr { public: T* px; detail::shared_count pn; T* get() const { return px; } };
namespace signals { class connection { public: void disconnect() const; char d[0x20]; }; }
}
namespace RBX {
class Instance;
class X {
public:
	char pad[0x70];
	boost::signals::connection conn;
	Instance* current;
	void update();
	void onRemoved(boost::shared_ptr<Instance> p);
};
void X::onRemoved(boost::shared_ptr<Instance> p)
{
	if (p.get() == current)
	{
		conn.disconnect();
		current = 0;
		update();
	}
}
}
