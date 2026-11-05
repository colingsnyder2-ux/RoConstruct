// from server: 12% by atomic.potato
struct S
{
    void f(void *);
};

void S::f(void *p)
{
    void *q = p;
    ((void (__thiscall *)(void *, void *))0x4f4af0)(q, &p);
}
