// from server: 100% by Xemicl
// roc 2012-06 00863340  unit: VWiniInetRequest_source::?$stream_buffer  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00863340
//
// 00863340  56                   push esi
// 00863341  8bf1                 mov esi, ecx
// 00863343  8b06                 mov eax, dword ptr [esi]
// 00863345  85c0                 test eax, eax
// 00863347  7418                 je 0x863361
// 00863349  83f8ff               cmp eax, -1
// 0086334c  741f                 je 0x86336d
// 0086334e  50                   push eax
// 0086334f  ff15e821b200         call dword ptr [0xb221e8]
// 00863355  8b442408             mov eax, dword ptr [esp + 8]
// 00863359  8906                 mov dword ptr [esi], eax
// 0086335b  8bc6                 mov eax, esi
// 0086335d  5e                   pop esi
// 0086335e  c20400               ret 4
// 00863361  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00863365  890e                 mov dword ptr [esi], ecx
// 00863367  8bc6                 mov eax, esi
// 00863369  5e                   pop esi
// 0086336a  c20400               ret 4
// 0086336d  8b542408             mov edx, dword ptr [esp + 8]
// 00863371  8916                 mov dword ptr [esi], edx
// 00863373  8bc6                 mov eax, esi
// 00863375  5e                   pop esi
// 00863376  c20400               ret 4
// copied from an identical function in another client (function ??4handle_manager@win32@detail@boost@@QAEAAV0123@PAX@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
namespace boost { namespace detail { namespace win32 {
typedef void* handle;
class handle_manager {
    handle handle_to_manage;
    void cleanup()
    {
        if (handle_to_manage && handle_to_manage != (handle)-1)
            CloseHandle(handle_to_manage);
    }
public:
    handle_manager& operator=(handle new_handle);
};
handle_manager& handle_manager::operator=(handle new_handle)
{
    cleanup();
    handle_to_manage = new_handle;
    return *this;
}
}}}