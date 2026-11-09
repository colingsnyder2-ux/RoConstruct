// from server: 71% by atomic.potato
typedef struct _CRITICAL_SECTION CRITICAL_SECTION;

extern "C" void __stdcall EnterCriticalSection(CRITICAL_SECTION *);
extern "C" void __stdcall LeaveCriticalSection(CRITICAL_SECTION *);

struct S
{
    int f(int, int);
};

int S::f(int unused, int value)
{
    CRITICAL_SECTION *section = *(CRITICAL_SECTION **)((char *)this + 0x10);
    EnterCriticalSection(section);
    *(int *)((char *)this + 0x1c) = value;
    LeaveCriticalSection(section);
    return 0;
}
