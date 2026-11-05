// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* __stdcall GetProcessHeap();
extern "C" __declspec(dllimport) int __stdcall HeapFree(void*, unsigned long, void*);
#include <intrin.h>
namespace boost {
namespace detail {
inline void free_raw_heap_memory(void* heap_memory) { HeapFree(GetProcessHeap(), 0, heap_memory); }
template<typename T> inline void heap_delete(T* data)
{
    if (data) { data->~T(); free_raw_heap_memory(data); }
}
struct thread_data_base {
    long count;
    virtual ~thread_data_base();
    virtual void run() = 0;
    friend void intrusive_ptr_add_ref(thread_data_base* p) { _InterlockedIncrement(&p->count); }
    friend void intrusive_ptr_release(thread_data_base* p)
    {
        if (!_InterlockedDecrement(&p->count)) detail::heap_delete(p);
    }
};
}
template<class T> class intrusive_ptr {
    typedef intrusive_ptr this_type;
    T* p_;
public:
    intrusive_ptr(T* p, bool add_ref = true) : p_(p) { if (p_ != 0 && add_ref) intrusive_ptr_add_ref(p_); }
    ~intrusive_ptr() { if (p_ != 0) intrusive_ptr_release(p_); }
    intrusive_ptr& operator=(T* rhs) { this_type(rhs).swap(*this); return *this; }
    void swap(intrusive_ptr& rhs) { T* tmp = p_; p_ = rhs.p_; rhs.p_ = tmp; }
};
template class intrusive_ptr<detail::thread_data_base>;
}
