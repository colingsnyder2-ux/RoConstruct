// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#pragma intrinsic(_InterlockedDecrement)
#pragma intrinsic(_InterlockedIncrement)
namespace boost { namespace detail {
class sp_counted_base {
public:
	virtual ~sp_counted_base() {}
	virtual void dispose() = 0;
	virtual void destroy() { delete this; }
	void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
	void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
	long use_count_;
	long weak_count_;
};
class shared_count {
public:
	shared_count() : pi_(0) {}
	shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) _InterlockedIncrement(&pi_->use_count_); }
	~shared_count() { if (pi_ != 0) pi_->release(); }
	sp_counted_base* pi_;
};
}
template<class T> class shared_ptr { public: T* px; detail::shared_count pn; };
}
namespace RBX { class XmlNameSpace; boost::shared_ptr<XmlNameSpace> createDefaultNameSpace();
__declspec(noinline) boost::shared_ptr<XmlNameSpace> getDefaultNameSpace() { static boost::shared_ptr<XmlNameSpace> ns = createDefaultNameSpace(); return ns; } }
void initDefaultNameSpace() { RBX::getDefaultNameSpace(); }
