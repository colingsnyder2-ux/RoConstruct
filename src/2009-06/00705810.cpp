// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
#pragma intrinsic(_InterlockedIncrement)
namespace boost {
template<class T> class intrusive_ptr {
public:
    intrusive_ptr(intrusive_ptr const& rhs) : p_(rhs.p_) { if (p_ != 0) intrusive_ptr_add_ref(p_); }
private:
    T* p_;
};
namespace detail {
class basic_cv_list_entry {
public:
    void* semaphore;
    void* wake_sem;
    long waiters;
    bool notified;
    long references;
    friend void intrusive_ptr_add_ref(basic_cv_list_entry* p) { _InterlockedIncrement(&p->references); }
};
}
template class intrusive_ptr<detail::basic_cv_list_entry>;
}
