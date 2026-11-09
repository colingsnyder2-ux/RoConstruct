// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedExchange(long volatile*, long);
#pragma intrinsic(_InterlockedExchange)
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
namespace boost {
namespace detail {
struct basic_timed_mutex {
    long active_count;
    void* event;
    void destroy()
    {
        void* const old_event = (void*)_InterlockedExchange((long*)&event, 0);
        if (old_event)
            CloseHandle(old_event);
    }
};
namespace win32 {
class handle_manager {
    void* handle_to_manage;
    void cleanup()
    {
        if (handle_to_manage && handle_to_manage != (void*)-1)
            CloseHandle(handle_to_manage);
    }
public:
    ~handle_manager() { cleanup(); }
};
}
}
class mutex : public detail::basic_timed_mutex {
public:
    ~mutex() { destroy(); }
};
template <class T> inline void checked_delete(T* x)
{
    typedef char type_must_be_complete[sizeof(T) ? 1 : -1];
    (void)sizeof(type_must_be_complete);
    delete x;
}
}
struct Container { ~Container() throw(); int d[6]; };
struct Data {
    boost::mutex m1;
    boost::mutex m2;
    int a, b;
    Container c;
    boost::detail::win32::handle_manager h;
};
template void boost::checked_delete<Data>(Data*);
