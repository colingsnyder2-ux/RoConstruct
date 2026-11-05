// from server: 94% by atomic.potato
extern "C" void __cdecl _invalid_parameter_noinfo();

struct S {
    char pad[0x98];
    int *m_98;
    int *f(int *);
};

int *S::f(int *p)
{
    int *x = m_98;
    int n = x[3];
    *p = 0;
    if ((unsigned int)n > (unsigned int)x[4])
        _invalid_parameter_noinfo();
    p[0] = x[0];
    p[1] = n;
    return p;
}
