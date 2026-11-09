// from server: 81% by atomic.potato
struct S
{
    void *vtable;
    char pad[24];
    void *value;
    void f(void *, void *);
};

typedef void *(__thiscall *Getter)(void *, void *);
typedef void (__thiscall *Init)(void *);

void S::f(void *a, void *b)
{
    void *p = *(void **)((char *)this + 0x1c);
    Getter get = *(Getter *)((char *)*(void **)p + 0x0c);
    void *x = get(p, a);

    S *q = (S *)((char *)b + 0x10);
    Init init = (Init)0x676f40;
    init(q);
    q->value = x;
    *(int *)((char *)q + 4) = 5;
}
