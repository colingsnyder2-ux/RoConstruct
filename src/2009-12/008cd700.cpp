// from server: 36% by atomic.potato
struct S
{
    void f();
};

extern "C" void __cdecl Function84D7A0(int);

void S::f()
{
    S *p = this;
    p->f();
    Function84D7A0(0);
}
