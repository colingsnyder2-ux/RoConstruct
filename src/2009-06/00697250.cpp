// from server: 70% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <exception>
extern "C" long __cdecl _InterlockedDecrement(long volatile*);
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
#pragma intrinsic(_InterlockedDecrement)
#pragma intrinsic(_InterlockedIncrement)
namespace boost { namespace detail {
class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    sp_counted_base(): use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_add_ref() { _InterlockedIncrement(&weak_count_); }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(): pi_(0) {}
    shared_count(const shared_count& r): pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
class weak_count {
public:
    sp_counted_base* pi_;
    weak_count(): pi_(0) {}
    ~weak_count() { if (pi_ != 0) pi_->weak_release(); }
};
}
template<class T> class shared_ptr { public: T* px; detail::shared_count pn; typedef T* shared_ptr::*unspecified_bool_type; operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; } T* operator->() const { return px; } };
template<class T> class weak_ptr { public: T* px; detail::weak_count pn; shared_ptr<T> lock() const throw(); };
}
namespace RBX {
class Instance { public: void setParent(Instance* p); };
enum MessageType { MESSAGE_OUTPUT, MESSAGE_INFO, MESSAGE_WARNING, MESSAGE_ERROR };
class StandardOut { public: static boost::shared_ptr<StandardOut> singleton(); void print(MessageType type, const std::exception& e); };
}
static void cleanup(boost::weak_ptr<RBX::Instance> item)
{
	try
	{
		boost::shared_ptr<RBX::Instance> i = item.lock();
		if (i)
			i->setParent(0);
	}
	catch (std::exception& e)
	{
		RBX::StandardOut::singleton()->print(RBX::MESSAGE_WARNING, e);
	}
}
void use_cleanup(boost::weak_ptr<RBX::Instance> w) { cleanup(w); }
