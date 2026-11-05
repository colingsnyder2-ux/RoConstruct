// from server: 69% by atomic.potato
extern "C" void f4098f0(void *, void *);

struct S
{
    int pad0[8];
    void *field20;
    S *f(void *);
};

S *S::f(void *arg)
{
    f4098f0(this, arg);
    field20 = (void *)0x0099fd90;
    *(void **)this = (void *)0x0099ff88;
    *(void **)((char *)this + 0x0c) = (void *)0x0099ff80;
    field20 = (void *)0x0099ff70;
    return this;
}
