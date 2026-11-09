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

extern "C" void __cdecl sub_5980d0();

S* g_5980d0 = 0;

void S::f()
{
    a = 0xa8fd54;
    b = 0xa8fd48;
    c = 0xa8fd3c;
    d = 0xa8fd30;
    sub_5980d0();
}
