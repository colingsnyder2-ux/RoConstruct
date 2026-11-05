// from server: 100% by atomic.potato
typedef struct
{
    unsigned char data[1];
} CRITICAL_SECTION;

extern "C" void (__stdcall *EnterCriticalSection)(CRITICAL_SECTION *);
extern "C" void (__stdcall *LeaveCriticalSection)(CRITICAL_SECTION *);

struct S
{
    unsigned char padding[0x144];
    CRITICAL_SECTION lock;
    unsigned char padding2[0x18];
    int value1;
    int value2;
    int f();
};

int S::f()
{
    EnterCriticalSection(&lock);
    value1 = 0;
    value2 = 0;
    LeaveCriticalSection(&lock);
    return 0;
}
