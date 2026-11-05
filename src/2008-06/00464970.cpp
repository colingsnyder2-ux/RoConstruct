// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

#include <vector>

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern void* __cdecl getContext();

struct S
{
    std::vector<void*> storage;
    unsigned long threadId;
    void* context;

    S();
    virtual ~S();
};

S::S()
{
    threadId = GetCurrentThreadId();
    context = getContext();
}
