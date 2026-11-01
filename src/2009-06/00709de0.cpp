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
    typedef T* intrusive_ptr::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &intrusive_ptr::px; }
    T* operator->() const { return px; }
    T* px;
};
namespace detail {
template<typename T> inline void heap_delete(T* data) { data->~T(); HeapFree(GetProcessHeap(), 0, data); }
struct timeout {
    unsigned long start;
    unsigned __int64 milliseconds;
    bool relative;
    __int64 abs_time;
    static timeout sentinel();
};
struct handle_manager { void* handle_to_manage; operator void*() const { return handle_to_manage; } };
struct thread_data_base {
    long count;
    handle_manager thread_handle;
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
    void release_handle();
    void join();
};
namespace this_thread { bool interruptible_wait(void* handle_to_wait_for, detail::timeout target_time); }
void thread::join()
{
    detail::thread_data_ptr local_thread_info = get_thread_info();
    if (local_thread_info) {
        this_thread::interruptible_wait(local_thread_info->thread_handle, detail::timeout::sentinel());
        release_handle();
    }
}
}
