// from server: 80% by atomic.potato
struct S {
    int f(int, int, int);
};

int S::f(int a, int b, int c)
{
    struct V {
        int (**vtable)();
    };

    S *p = (S *)((char *)a - 204);
    V *q = *(V **)((char *)p + 32);
    typedef int (__thiscall *F)(V *, int, int, int);
    F fn = (F)q->vtable[115];
    return fn(q, c, b, a);
}
