// from server: 100% by atomic.potato
typedef struct _CRITICAL_SECTION CRITICAL_SECTION;

extern "C" void __declspec(dllimport) __stdcall EnterCriticalSection(CRITICAL_SECTION *);
extern "C" void __declspec(dllimport) __stdcall LeaveCriticalSection(CRITICAL_SECTION *);

struct S
{
    char pad[84];
    void *field54;
    int f();
};

int S::f()
{
    void *p = field54;
    void *v = *(void **)p;
    CRITICAL_SECTION *c = (CRITICAL_SECTION *)((char *)v + 0xf0);
    EnterCriticalSection(c);
    int r = *(int *)((char *)v + 0x128);
    LeaveCriticalSection(c);
    return r;
}
