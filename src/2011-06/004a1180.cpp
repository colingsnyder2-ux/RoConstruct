// from server: 91% by atomic.potato
typedef struct _CRITICAL_SECTION CRITICAL_SECTION;

extern "C" void __stdcall EnterCriticalSection(CRITICAL_SECTION *);
extern "C" void __stdcall LeaveCriticalSection(CRITICAL_SECTION *);

struct CVideoStream
{
    int f(CVideoStream *, int);
};

int CVideoStream::f(CVideoStream *object, int value)
{
    CRITICAL_SECTION *section =
        *(CRITICAL_SECTION **)((char *)object + 0x10);
    EnterCriticalSection(section);
    *(int *)((char *)object + 0x1c) = value;
    LeaveCriticalSection(section);
    return 0;
}
