// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
namespace boost {
namespace detail {
namespace win32 {
typedef void* handle;
class handle_manager {
    handle handle_to_manage;
    void cleanup()
    {
        if (handle_to_manage && handle_to_manage != (handle)-1)
            CloseHandle(handle_to_manage);
    }
public:
    explicit handle_manager(handle h) : handle_to_manage(h) {}
    ~handle_manager() { cleanup(); }
};
}
struct thread_exit_callback_node;
struct tss_data_node;
struct thread_data_base {
    long count;
    win32::handle_manager thread_handle;
    win32::handle_manager interruption_handle;
    thread_exit_callback_node* thread_exit_callbacks;
    tss_data_node* tss_data;
    bool interruption_enabled;
    unsigned id;
    thread_data_base();
    virtual ~thread_data_base() {}
    virtual void run() = 0;
};
thread_data_base::thread_data_base()
    : count(0), thread_handle((win32::handle)-1), interruption_handle(0),
      thread_exit_callbacks(0), tss_data(0), interruption_enabled(true), id(0) {}
}
}
