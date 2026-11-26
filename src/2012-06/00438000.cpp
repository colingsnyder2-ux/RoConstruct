// from server: 100% by Xemicl
// roc 2012-06 00438000  unit: boost::detail::thread_data_base  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00438000
//
// 00438000  56                   push esi
// 00438001  8bf1                 mov esi, ecx
// 00438003  c70678f7b400         mov dword ptr [esi], 0xb4f778
// 00438009  8b460c               mov eax, dword ptr [esi + 0xc]
// 0043800c  57                   push edi
// 0043800d  8b3de821b200         mov edi, dword ptr [0xb221e8]
// 00438013  85c0                 test eax, eax
// 00438015  7408                 je 0x43801f
// 00438017  83f8ff               cmp eax, -1
// 0043801a  7403                 je 0x43801f
// 0043801c  50                   push eax
// 0043801d  ffd7                 call edi
// 0043801f  8b4608               mov eax, dword ptr [esi + 8]
// 00438022  85c0                 test eax, eax
// 00438024  7408                 je 0x43802e
// 00438026  83f8ff               cmp eax, -1
// 00438029  7403                 je 0x43802e
// 0043802b  50                   push eax
// 0043802c  ffd7                 call edi
// 0043802e  f644240c01           test byte ptr [esp + 0xc], 1
// 00438033  7409                 je 0x43803e
// 00438035  56                   push esi
// 00438036  e8d9a05400           call 0x982114
// 0043803b  83c404               add esp, 4
// 0043803e  5f                   pop edi
// 0043803f  8bc6                 mov eax, esi
// 00438041  5e                   pop esi
// 00438042  c20400               ret 4
// copied from an identical function in another client (function ??_Gthread_data_base@detail@boost@@UAEPAXI@Z)

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