// from server: 100% by atomic.potato
typedef unsigned long DWORD;

struct CRITICAL_SECTION
{
    DWORD data[6];
};

extern "C" void __declspec(dllimport) __stdcall EnterCriticalSection(CRITICAL_SECTION *);
extern "C" void __declspec(dllimport) __stdcall LeaveCriticalSection(CRITICAL_SECTION *);

struct MarshaledListener
{
    void *vtable;
    char padding[0x1c];
    CRITICAL_SECTION *section;
    void f(void *, void *);
};

void MarshaledListener::f(void *b, void *a)
{
    CRITICAL_SECTION *lock = (CRITICAL_SECTION *)((char *)section + 0x2c);
    EnterCriticalSection(lock);
    ((void (__thiscall *)(MarshaledListener *, void *, void *))(*(void **)(*(char **)this + 0x0c)))(this, b, a);
    LeaveCriticalSection(lock);
}
