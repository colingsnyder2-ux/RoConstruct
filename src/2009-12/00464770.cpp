// from server: 78% by atomic.potato
extern "C" void sub_464560(void *);
extern "C" void __stdcall sub_7f385a(void *);

struct S
{
    int f(int);
};

int S::f(int a)
{
    *(void **)((char *)this + 0xc) = (void *)0x9aea20;
    sub_464560((char *)this + 0xc);
    if (a & 1)
        sub_7f385a(this);
    return (int)this;
}
