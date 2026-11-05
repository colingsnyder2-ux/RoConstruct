// from server: 63% by atomic.potato
typedef unsigned long DWORD;

struct CRITICAL_SECTION
{
    DWORD data[6];
};

extern "C" void __stdcall EnterCriticalSection(CRITICAL_SECTION *);
extern "C" void __stdcall LeaveCriticalSection(CRITICAL_SECTION *);

struct S
{
    int f();
    CRITICAL_SECTION lock;
    int count;
    char padding[28];
    int begin;
    int end;
};

int S::f()
{
    EnterCriticalSection(&lock);
    ++count;
    if (count == (end - begin) / 4)
        count = 0;
    LeaveCriticalSection(&lock);
    return 0;
}
