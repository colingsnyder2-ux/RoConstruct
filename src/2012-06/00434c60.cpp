// from server: 100% by Xemicl
// roc 2012-06 00434c60  unit: MainLogManager  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00434c60
//
// 00434c60  56                   push esi
// 00434c61  8bf1                 mov esi, ecx
// 00434c63  c70678f7b400         mov dword ptr [esi], 0xb4f778
// 00434c69  8b460c               mov eax, dword ptr [esi + 0xc]
// 00434c6c  57                   push edi
// 00434c6d  8b3de821b200         mov edi, dword ptr [0xb221e8]
// 00434c73  85c0                 test eax, eax
// 00434c75  7408                 je 0x434c7f
// 00434c77  83f8ff               cmp eax, -1
// 00434c7a  7403                 je 0x434c7f
// 00434c7c  50                   push eax
// 00434c7d  ffd7                 call edi
// 00434c7f  8b7608               mov esi, dword ptr [esi + 8]
// 00434c82  85f6                 test esi, esi
// 00434c84  7408                 je 0x434c8e
// 00434c86  83feff               cmp esi, -1
// 00434c89  7403                 je 0x434c8e
// 00434c8b  56                   push esi
// 00434c8c  ffd7                 call edi
// 00434c8e  5f                   pop edi
// 00434c8f  5e                   pop esi
// 00434c90  c3                   ret 
// copied from an identical function in another client (function ??1thread_data_base@detail@boost@@UAE@XZ)

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