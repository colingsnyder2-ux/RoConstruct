// from server: 65% by atomic.potato
struct S_func_005df9c0 {
    char pad[16];
    int *m_value;
    int *f(int *a, int b);
};

int *S_func_005df9c0::f(int *a, int b)
{
    int *p = m_value;
    if (p == 0) {
        *a = 0;
        return 0;
    }
    typedef void (__thiscall *Fn)(int *, int *, int);
    Fn fn = (Fn)(*(int **)*p + 36);
    fn(p, a, b);
    return a;
}
