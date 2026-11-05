// from server: 93% by atomic.potato
struct S
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int value;
    int g;
    int h;

    void f();
};

extern "C" void __cdecl target();

void S::f()
{
    a = 0x00B6FB14;
    b = 0x00B6FB0C;
    e = 0x00B6FB00;
    value = 0x00B6FAF4;
    target();
}
