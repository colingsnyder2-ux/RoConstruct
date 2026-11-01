// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
#include <intrin.h>
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
namespace boost {
template<class T> class intrusive_ptr {
public:
    ~intrusive_ptr() { if (p_ != 0) intrusive_ptr_release(p_); }
    T* p_;
};
namespace detail {
namespace win32 {
class handle_manager {
    void* handle_to_manage;
    void cleanup() { if (handle_to_manage && handle_to_manage != (void*)-1) CloseHandle(handle_to_manage); }
public:
    ~handle_manager() { cleanup(); }
};
}
class basic_cv_list_entry;
void intrusive_ptr_release(basic_cv_list_entry* p);
class basic_cv_list_entry {
    win32::handle_manager semaphore;
    win32::handle_manager wake_sem;
    long waiters;
    bool notified;
    long references;
    friend void intrusive_ptr_release(basic_cv_list_entry* p);
};
inline void intrusive_ptr_release(basic_cv_list_entry* p)
{
    if (!_InterlockedDecrement(&p->references))
        delete p;
}
}
}
typedef boost::intrusive_ptr<boost::detail::basic_cv_list_entry> entry_ptr;
template void std::_Destroy_range(entry_ptr*, entry_ptr*, std::allocator<entry_ptr>&, std::_Nonscalar_ptr_iterator_tag);
