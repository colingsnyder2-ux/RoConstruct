// from server: 80% by atomic.potato
extern "C" void G1_func_005b2a40(void *destination, void *source);

struct S
{
    S *f(S *other);
};

S *S::f(S *other)
{
    *(int *)this = *(int *)other;
    G1_func_005b2a40((char *)this + 4, (char *)other + 4);
    *(int *)((char *)this + 0x10) = *(int *)((char *)other + 0x10);
    *(int *)((char *)this + 0x14) = *(int *)((char *)other + 0x14);
    return this;
}
