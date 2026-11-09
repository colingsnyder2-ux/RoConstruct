// from server: 100% by atomic.potato
struct S {
    int f();
};

int S::f()
{
    struct T {
        char pad[12];
        int unused;
        int end;
    };
    T *p = *(T **)((char *)this + 0x154);
    return (p->end - *(int *)((char *)p + 0xc)) >> 3;
}
