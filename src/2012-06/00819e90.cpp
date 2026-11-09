// from server: 100% by atomic.potato
struct S
{
    int a;
    int b;
    int pad0[4];
    int c;
    int d;

    void f();
};

extern "C" void continuation();

void S::f()
{
    a = 0x00BC83D4;
    b = 0x00BC83CC;
    c = 0x00BC83C0;
    d = 0x00BC83B4;
    continuation();
}
