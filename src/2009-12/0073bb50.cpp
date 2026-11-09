// from server: 80% by atomic.potato
struct S {
    int f(int, double, int, int, int);
    void **vtable;
};

int S::f(int a, double b, int c, int d, int e)
{
    void **p = *(void ***)((char *)this + 8);
    void (__thiscall *fn)(void *, int, double, int, int) =
        (void (__thiscall *)(void *, int, double, int, int))
        (*(void **)(*(void ***)p + 0x2c));
    fn(p, a, b, c, d);
    return a;
}
