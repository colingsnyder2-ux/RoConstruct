// from server: 83% by atomic.potato
extern "C" void __cdecl sub_7599c0(void *, void *);

struct S
{
    S *f(void *, void *);
};

S *S::f(void *a, void *b)
{
    sub_7599c0(b, a);
    *(unsigned long *)this = 0xAB54B4;
    *(unsigned long *)((char *)this + 0x2C) = 0;
    return this;
}
