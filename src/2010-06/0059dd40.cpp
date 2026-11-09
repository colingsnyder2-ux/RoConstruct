// from server: 70% by atomic.potato
struct S
{
    typedef void (__thiscall *Fn)(double, double);

    void f(void *p, double a, double b);
};

void S::f(void *p, double a, double b)
{
    char *q = (char *)p;
    Fn fn = *(Fn *)q;
    fn(a, b);
}
