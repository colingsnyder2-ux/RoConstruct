// from server: 100% by atomic.potato
extern "C" void sub_007a84d4();

struct S
{
    S *f();
};

S *S::f()
{
    sub_007a84d4();
    *(void **)this = (void *)0x00a118d4;
    *((unsigned char *)this + 0xf4) = 0;
    return this;
}
