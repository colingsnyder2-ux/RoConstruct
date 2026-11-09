// from server: 100% by atomic.potato
typedef struct _CRITICAL_SECTION
{
    int Reserved1;
    int Reserved2;
    int Reserved3;
    int Reserved4;
    int Reserved5;
    int Reserved6;
} CRITICAL_SECTION;

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION *);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION *);

struct CAudioStream
{
    int f();
};

int CAudioStream::f()
{
    CRITICAL_SECTION *cs = (CRITICAL_SECTION *)((char *)this + 0x130);
    EnterCriticalSection(cs);
    *(int *)((char *)this + 0x148) = 0;
    *(int *)((char *)this + 0x14c) = 0;
    LeaveCriticalSection(cs);
    return 0;
}
