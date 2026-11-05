// from server: 100% by atomic.potato


struct S
{
    S *f(void *, void *);
void sub_7599C0(void *, void *);
};

S *S::f(void *a, void *b)
{
    sub_7599C0(a, b);
    *(unsigned long *)this = 0xAB54E4;
    *(unsigned long *)((char *)this + 0x2C) = 0;
    return this;
}
