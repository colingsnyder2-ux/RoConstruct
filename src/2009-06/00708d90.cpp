// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS /EHsc /MD
#include <intrin.h>
extern "C" __declspec(dllimport) void* __stdcall GetProcessHeap();
extern "C" __declspec(dllimport) int __stdcall HeapFree(void*, unsigned long, void*);
namespace boost {
namespace detail {
struct thread_data_base {
    long count;
    virtual ~thread_data_base();
};
inline void free_raw_heap_memory(void* heap_memory) { HeapFree(GetProcessHeap(), 0, heap_memory); }
template<typename T> inline void heap_delete(T* data) { data->~T(); free_raw_heap_memory(data); }
inline void intrusive_ptr_add_ref(thread_data_base* p) { _InterlockedIncrement(&p->count); }
inline void intrusive_ptr_release(thread_data_base* p) { if (!_InterlockedDecrement(&p->count)) heap_delete(p); }
thread_data_base* get_or_make_current_thread_data();
}
template<class T> class intrusive_ptr {
public:
    intrusive_ptr(T* p = 0, bool add_ref = true) : px(p) { if (px != 0 && add_ref) intrusive_ptr_add_ref(px); }
    intrusive_ptr(intrusive_ptr const& rhs) : px(rhs.px) { if (px != 0) intrusive_ptr_add_ref(px); }
    ~intrusive_ptr() { if (px != 0) intrusive_ptr_release(px); }
    T* px;
};
namespace detail { typedef intrusive_ptr<thread_data_base> thread_data_ptr; }
class thread {
public:
    class id {
    public:
        detail::thread_data_ptr thread_data;
        id(detail::thread_data_ptr thread_data_);
    };
};
namespace this_thread {
thread::id get_id()
{
    return thread::id(detail::get_or_make_current_thread_data());
}
}
}
