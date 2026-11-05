// from server: 72% by atomic.potato
struct S
{
    int *p;
    char *data;

    int f(int);
};

typedef void (__thiscall *F)(void *, void *, int);

int S::f(int)
{
    if (p != 0)
    {
        F fn = (F)(*p);
        if (fn != 0)
            fn((char *)this + 8, (char *)this + 8, 2);
        p = 0;
    }
    return 0;
}
