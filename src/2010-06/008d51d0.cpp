// from server: 81% by atomic.potato
struct S
{
    S *f();
};

S *S::f()
{
    S *p = *(S **)((char *)this + 4);
    while (*(unsigned char *)((char *)(*(S **)p) + 0x71) == 0)
        p = *(S **)p;
    return p;
}
