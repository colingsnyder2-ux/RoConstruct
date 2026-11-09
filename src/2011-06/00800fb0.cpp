// from server: 88% by atomic.potato
typedef unsigned long DWORD;

struct CRITICAL_SECTION
{
    DWORD data[6];
};

extern "C" void __declspec(dllimport) __stdcall EnterCriticalSection(CRITICAL_SECTION *);
extern "C" void __declspec(dllimport) __stdcall LeaveCriticalSection(CRITICAL_SECTION *);

struct S
{
    int value;
    int index;
    CRITICAL_SECTION lock;
    int *begin;
    int *end;
    void f();
};

void S::f()
{
    int *p = (int *)((char *)this + 8);
    EnterCriticalSection((CRITICAL_SECTION *)p);
    ++index;
    if (index == (end - begin))
        index = 0;
    LeaveCriticalSection((CRITICAL_SECTION *)p);
}
