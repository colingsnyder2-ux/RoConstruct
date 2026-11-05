// from server: 65% by atomic.potato
extern "C" int G1_func_00711690(void *a, void *b);

struct S
{
    void f(void *, void *);
};

void S::f(void *a, void *b)
{
    int local;
    int *p = *(int **)((char *)this + 0x28);
    int *q = (int *)((char *)p[0] + 0x0c);
    int value = G1_func_00711690(a, &local);
    typedef void (__thiscall *Fn)(void *, void *, int);
    ((Fn)(*(void **)q))(p, b, value);
}
