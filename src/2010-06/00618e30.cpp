// from server: 100% by atomic.potato
struct S
{
    int a[8];
    void f();
};

extern "C" void __cdecl g();

void S::f()
{
    a[0] = 0xa31b94;
    a[1] = 0xa31b8c;
    a[6] = 0xa31b80;
    a[7] = 0xa31b74;
    g();
}
