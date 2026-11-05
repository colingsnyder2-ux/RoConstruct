// from server: 40% by atomic.potato
struct S
{
    unsigned char f(unsigned char, int *);
};

unsigned char S::f(unsigned char value, int *p)
{
    int *q = 0;
    if (p != reinterpret_cast<int *>(&value))
    {
        q = reinterpret_cast<int *>(*p);
        *p = 0;
    }
    if (q)
    {
        int *v = reinterpret_cast<int *>(*q);
        typedef void (__thiscall *F)(int *, int);
        F fn = reinterpret_cast<F>(*v);
        fn(q, 1);
    }
    return value;
}
