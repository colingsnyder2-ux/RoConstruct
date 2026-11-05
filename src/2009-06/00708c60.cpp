// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// boost 1.36 thread::thread(detail::thread_data_ptr) (libs/thread/src/win32/thread.cpp)
#include <intrin.h>
extern "C" __declspec(dllimport) void* __stdcall GetProcessHeap();
extern "C" __declspec(dllimport) int __stdcall HeapFree(void*, unsigned long, void*);
namespace boost {
namespace detail {
template<class T> inline void heap_delete(T* data) { data->~T(); HeapFree(GetProcessHeap(), 0, data); }
struct thread_data_base { virtual ~thread_data_base(); long count; };
inline void intrusive_ptr_add_ref(thread_data_base* p) { _InterlockedIncrement(&p->count); }
inline void intrusive_ptr_release(thread_data_base* p) { if (!_InterlockedDecrement(&p->count)) heap_delete(p); }
template<class T> struct intrusive_ptr {
    T* p_;
    intrusive_ptr(const intrusive_ptr& r) : p_(r.p_) { if (p_ != 0) intrusive_ptr_add_ref(p_); }
    ~intrusive_ptr() { if (p_ != 0) intrusive_ptr_release(p_); }
};
typedef intrusive_ptr<thread_data_base> thread_data_ptr;
}
class thread {
    detail::thread_data_ptr thread_info;
public:
    explicit thread(detail::thread_data_ptr data);
};
thread::thread(detail::thread_data_ptr data) : thread_info(data) {}
}
