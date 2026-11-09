// from server: 53% by atomic.potato
typedef void (__thiscall *F)(void *, void *);

struct S
{
    void f(void *, void *);
};

void S::f(void *a, void *b)
{
    void **v = *(void ***)a;
    F fn = (F)v[3];
    fn((char *)this + 8, b);
}
