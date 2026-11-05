// from server: 54% by atomic.potato
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void *);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void *);
extern "C" __declspec(dllimport) int __stdcall SetEvent(void *);

struct Inner
{
    char pad[0x18];
    unsigned int m18;
    unsigned int m1c;
    void method();
};

struct S
{
    char pad0[0xf0];
    void *m0f0;
    char pad0f4[0x14];
    void *m108;
    Inner m10c;
    void f(int, int, int, int, int);
};

void S::f(int a1, int a2, int a3, int a4, int a5)
{
    EnterCriticalSection(&m0f0);
    Inner tmp;
    tmp.m18 = a1;
    tmp.m1c = a2;
    tmp.method();
    SetEvent(m108);
    LeaveCriticalSection(&m0f0);
}
