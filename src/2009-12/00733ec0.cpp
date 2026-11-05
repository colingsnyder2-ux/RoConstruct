// from server: 57% by atomic.potato
extern "C" long __declspec(dllimport) __stdcall InterlockedExchange(long *, long);
extern "C" void __stdcall sub_7f385a();

struct S {
    void f();
};

void S::f()
{
    sub_7f385a();
    char pad[0x14];
    *(long *)(pad + 0x10) = -1;
    InterlockedExchange((long *)(pad + 0), 0);
}
