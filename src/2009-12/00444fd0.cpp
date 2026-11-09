// from server: 50% by atomic.potato
struct S
{
    int f(void *);
    int *v;
};

typedef int (*Method)(void *, void *);

extern "C" int __cdecl sub_444ec0(int, int);

int S::f(void *arg)
{
    void *p;
    Method m;

    p = (void *)v[7];
    m = *(Method *)*(int **)p;
    return sub_444ec0((int)arg, m(p, &arg));
}
