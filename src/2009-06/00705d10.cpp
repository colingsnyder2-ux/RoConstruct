// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <xutility>
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
namespace boost {
template<class T> class intrusive_ptr {
public:
    intrusive_ptr(intrusive_ptr const& rhs) : p_(rhs.p_) { if (p_ != 0) intrusive_ptr_add_ref(p_); }
    ~intrusive_ptr() { if (p_ != 0) intrusive_ptr_release(p_); }
    intrusive_ptr& operator=(intrusive_ptr const& rhs) { intrusive_ptr(rhs).swap(*this); return *this; }
    void swap(intrusive_ptr& rhs) { T* tmp = p_; p_ = rhs.p_; rhs.p_ = tmp; }
private:
    T* p_;
};
namespace detail { namespace win32 {
typedef void* handle;
class handle_manager {
    handle handle_to_manage;
    void cleanup() {
        if (handle_to_manage && handle_to_manage != (handle)-1) CloseHandle(handle_to_manage);
    }
public:
    ~handle_manager() { cleanup(); }
};
}
class basic_cv_list_entry {
public:
    win32::handle_manager semaphore;
    win32::handle_manager wake_sem;
    long waiters;
    bool notified;
    long references;
    friend void intrusive_ptr_add_ref(basic_cv_list_entry* p) { _InterlockedIncrement(&p->references); }
    friend void intrusive_ptr_release(basic_cv_list_entry* p) { if (!_InterlockedDecrement(&p->references)) delete p; }
};
}
}
typedef boost::intrusive_ptr<boost::detail::basic_cv_list_entry> EP;
template void std::_Fill<EP*, EP>(EP*, EP*, const EP&);
