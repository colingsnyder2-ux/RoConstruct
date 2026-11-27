// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <exception>
extern "C" {
__declspec(dllimport) void* __stdcall CreateEventA(void*, int, int, const char*);
__declspec(dllimport) int __stdcall CloseHandle(void*);
long __cdecl _InterlockedCompareExchange(long volatile*, long, long);
}
#pragma intrinsic(_InterlockedCompareExchange)
namespace boost {
class __declspec(dllimport) thread_exception : public std::exception {
protected:
    thread_exception();
    thread_exception(int sys_err_code);
public:
    ~thread_exception() throw();
    int native_error() const;
private:
    int m_sys_err;
};
class __declspec(dllimport) thread_resource_error : public thread_exception {
public:
    thread_resource_error();
    ~thread_resource_error() throw();
};
namespace detail {
namespace win32 {
    enum event_type { auto_reset_event = false, manual_reset_event = true };
    enum initial_event_state { event_initially_reset = false, event_initially_set = true };
    inline void* create_anonymous_event(event_type type, initial_event_state state)
    {
        void* const res = CreateEventA(0, type, state, 0);
        if (!res) throw thread_resource_error();
        return res;
    }
}
inline void* interlocked_read_acquire(void* volatile* x) { return *x; }
struct basic_timed_mutex {
    long active_count;
    void* event;
    void* get_event();
};
void* basic_timed_mutex::get_event()
{
    void* current_event = ::boost::detail::interlocked_read_acquire(&event);
    if (!current_event)
    {
        void* const new_event = win32::create_anonymous_event(win32::auto_reset_event, win32::event_initially_reset);
        void* const old_event = (void*)_InterlockedCompareExchange((long volatile*)&event, (long)new_event, 0);
        if (old_event != 0)
        {
            CloseHandle(new_event);
            return old_event;
        }
        else
        {
            return new_event;
        }
    }
    return current_event;
}
}}
