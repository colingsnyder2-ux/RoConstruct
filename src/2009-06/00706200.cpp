// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <intrin.h>
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)

namespace boost {
struct once_flag { long status; long count; long throw_count; void* event_handle; };
template<typename F> void call_once(once_flag& flag, F f);

namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_; long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
struct tss_cleanup_function { virtual ~tss_cleanup_function() {} virtual void operator()(void*) = 0; };
}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
};
namespace detail {
void* get_tss_data(void const* key);
void set_tss_data(void const* key, boost::shared_ptr<tss_cleanup_function> func, void* tss_data, bool cleanup_existing);
}
template<typename T> class thread_specific_ptr {
    boost::shared_ptr<detail::tss_cleanup_function> cleanup;
public:
    T* get() const { return static_cast<T*>(detail::get_tss_data(this)); }
    void reset(T* new_value = 0) {
        T* const current_value = get();
        if (current_value != new_value)
            detail::set_tss_data(this, cleanup, new_value, true);
    }
};
}

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
void SetThreadName(unsigned long threadId, const char* name);

static boost::thread_specific_ptr<std::string>* threadName;
static boost::once_flag threadNameFlag;
static void initThreadName();

static boost::thread_specific_ptr<std::string>& getThreadName()
{
    boost::call_once(threadNameFlag, initThreadName);
    return *threadName;
}

void setThreadName(const char* name)
{
    getThreadName().reset(new std::string(name));
    SetThreadName(GetCurrentThreadId(), name);
}

void initThreadNameImpl();
static void initThreadName() { initThreadNameImpl(); }
