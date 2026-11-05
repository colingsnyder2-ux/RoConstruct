// from server: 100% by atomic.potato
typedef struct CRITICAL_SECTION {
    unsigned char data[24];
} CRITICAL_SECTION;

extern "C" void (__stdcall *EnterCriticalSection)(CRITICAL_SECTION *);
extern "C" void (__stdcall *LeaveCriticalSection)(CRITICAL_SECTION *);

struct S {
    unsigned char pad[0x130];
    CRITICAL_SECTION cs;
    int value148;
    int value14c;
    int f();
};

int S::f()
{
    EnterCriticalSection(&cs);
    value148 = 0;
    value14c = 0;
    LeaveCriticalSection(&cs);
    return 0;
}
