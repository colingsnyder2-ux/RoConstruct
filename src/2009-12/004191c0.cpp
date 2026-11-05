// from server: 100% by atomic.potato
struct S
{
    int f(void *, void *);
};

int S::f(void *a, void *b)
{
    struct V
    {
        void **vtable;
    };

    V *p = *(V **)((char *)a - 204);
    V *q = *(V **)((char *)p + 32);
    return ((int (__thiscall *)(V *, void *))q->vtable[109])(q, b);
}
