// from server: 68% by atomic.potato
struct S
{
    int f(void *a, void *b);
};

int S::f(void *a, void *b)
{
    void *p = a ? (char *)a + 0x1c : 0;
    void *q = *(void **)b;
    void **v = *(void ***)((char *)this + 0x134);
    typedef void (__thiscall *Fn)(void *, void *, void *);
    ((Fn)(*(void **)((char *)*v + 0x40)))(*v, p, q);
    return 0;
}
