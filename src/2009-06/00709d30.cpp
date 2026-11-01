// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS /EHsc /MD
extern "C" __declspec(dllimport) void* __stdcall GetProcessHeap();
extern "C" __declspec(dllimport) int __stdcall HeapFree(void*, unsigned long, void*);
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)
namespace boost {
template<class T> class intrusive_ptr {
public:
    intrusive_ptr(const intrusive_ptr& r): px(r.px) { if (px != 0) intrusive_ptr_add_ref(px); }
    ~intrusive_ptr() { if (px != 0) intrusive_ptr_release(px); }
    T* px;
};
namespace detail {
template<typename T> inline void heap_delete(T* data) { data->~T(); HeapFree(GetProcessHeap(), 0, data); }
struct thread_data_base {
    long count;
    virtual ~thread_data_base();
    friend void intrusive_ptr_add_ref(thread_data_base* p) { _InterlockedIncrement(&p->count); }
    friend void intrusive_ptr_release(thread_data_base* p) { if (!_InterlockedDecrement(&p->count)) detail::heap_delete(p); }
};
typedef intrusive_ptr<thread_data_base> thread_data_ptr;
}
class thread {
public:
    class id {
        detail::thread_data_ptr thread_data;
    public:
        id(detail::thread_data_ptr thread_data_);
    };
    detail::thread_data_ptr get_thread_info() const;
    id get_id() const;
};
thread::id thread::get_id() const
{
    return thread::id(get_thread_info());
}
}
