// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
struct Base_t {
    char storage[0x98];
    ~Base_t();
};
struct Aggregate_t {
    char storage[0x24];
    ~Aggregate_t();
};
struct Member_t {
    char storage[0x14];
    ~Member_t();
};
struct Mutex_t {
    void* event;
    ~Mutex_t()
    {
        void* const old_event = (void*)_InterlockedExchange((long*)&event, 0);
        if (old_event)
            CloseHandle(old_event);
    }
};
struct S_t : Base_t {
    Aggregate_t aggregate;
    Member_t member;
    Mutex_t mutex;
    ~S_t();
};
S_t::~S_t()
{
}
