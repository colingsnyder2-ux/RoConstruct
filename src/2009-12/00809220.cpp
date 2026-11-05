// from server: 100% by atomic.potato
struct S_sub_00809110 {
    void g(void *);
};

struct S_func_00809220 {
    char pad0[48];
    S_sub_00809110 sub;
    int f(void *);
};

int S_func_00809220::f(void *p)
{
    sub.g(p);
    return (int)p;
}
