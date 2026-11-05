// from server: 63% by atomic.potato
extern "C" int __cdecl CheckFlag(int);

struct T
{
    int pad;
    int *p;
};

struct S
{
    int f();
    int pad;
    T *p;
};

int S::f()
{
    if (p == 0)
        return 0;

    if (CheckFlag(15))
        return p->p[0];

    return p->p[2];
}
