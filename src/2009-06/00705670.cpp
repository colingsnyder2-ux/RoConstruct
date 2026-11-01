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
