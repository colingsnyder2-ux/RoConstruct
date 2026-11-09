// from server: 92% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    *(unsigned long *)this = 0x00bbebb4UL;
    *(unsigned long *)((char *)this + 4) = 0x00bbeba8UL;
    *(unsigned long *)((char *)this + 0x18) = 0x00bbeb9cUL;
    *(unsigned long *)((char *)this + 0x1c) = 0x00bbeb90UL;
    *(unsigned long *)((char *)this + 0x80) = 0x00bbeb88UL;
}
