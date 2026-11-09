// from server: 100% by atomic.potato
extern "C" void Function5980D0();

struct S
{
    void f();
    int m0;
    int m1;
    int pad[4];
    int m18;
    int m1c;
};

void S::f()
{
    *((int*)0x00cb22f0) = 0;
    m0 = 0x00a6cabc;
    m1 = 0x00a6cab0;
    m18 = 0x00a6caa4;
    m1c = 0x00a6ca98;
    Function5980D0();
}
