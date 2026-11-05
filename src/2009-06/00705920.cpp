// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
struct handle_manager {
    void* h;
    ~handle_manager() { if (h && h != (void*)-1) CloseHandle(h); }
};
struct thread_data {
    handle_manager thread_handle;
    handle_manager interruption_handle;
    int a, b;
    long count;
};
void intrusive_ptr_release(thread_data* p)
{
    if (!_InterlockedDecrement(&p->count))
        delete p;
}
