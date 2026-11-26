// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// boost::detail::thread_data_base constructor (boost 1.36 win32), standalone;
// boost::thread_resource_error comes from the boost_thread DLL, so its constructor is an import.
#include <exception>
extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void*, int, int, const char*);
namespace boost {
class __declspec(dllimport) thread_resource_error : public std::exception {
public:
    thread_resource_error();
    ~thread_resource_error() throw();
    int native_error;
};
namespace detail {
namespace win32 {
    typedef void* handle;
    inline handle create_anonymous_event(int type, int state)
    {
        handle const res = CreateEventA(0, type, state, 0);
        if (!res)
            throw thread_resource_error();
        return res;
    }
    class handle_manager {
        handle handle_to_manage;
    public:
        explicit handle_manager(handle h) : handle_to_manage(h) {}
        ~handle_manager();
    };
}
struct thread_data_base {
    long count;
    win32::handle_manager thread_handle;
    win32::handle_manager interruption_handle;
    void* thread_exit_callbacks;
    void* tss_data;
    bool interruption_enabled;
    unsigned id;
    thread_data_base();
    virtual ~thread_data_base();
};
thread_data_base::thread_data_base()
    : count(0), thread_handle((win32::handle)-1),
      interruption_handle(win32::create_anonymous_event(1, 0)),
      thread_exit_callbacks(0), tss_data(0), interruption_enabled(true), id(0)
{
}
}}