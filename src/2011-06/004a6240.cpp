// from server: 100% by atomic.potato
struct S
{
    int a;
    int b;
    int pad[4];
    int c;
    int d;
    void f();
};

extern "C" void __cdecl G1_func_005980d0();

void S::f()
{
    a = 0xa76b6c;
    b = 0xa76b60;
    c = 0xa76b54;
    d = 0xa76b48;
    G1_func_005980d0();
}
