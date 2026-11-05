// from server: 78% by atomic.potato
struct S
{
    int a;
    int b;
    int c;
    int d;
    void f();
};

extern "C" void __cdecl target();

void S::f()
{
    a = 0x00b928ec;
    b = 0x00b928e4;
    c = 0x00b928d8;
    d = 0x00b928cc;
    target();
}
