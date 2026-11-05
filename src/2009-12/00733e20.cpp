// from server: 59% by atomic.potato
extern "C" long __declspec(dllimport) __stdcall InterlockedExchange(long *, long);
extern "C" void __stdcall sub_7f385a(int);
extern "C" void __stdcall sub_7e1e80(void *);

struct S {
    void f();
};

void S::f()
{
    sub_7f385a(0);
    char buf[16];
    *(int*)(buf + 12) = -1;
    sub_7e1e80(buf);
    InterlockedExchange((long*)0, 0);
}
