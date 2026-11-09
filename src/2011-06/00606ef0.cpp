// from server: 51% by atomic.potato
struct S
{
    int f(const char *);
};

extern "C" void G1_func_00606b80(S *, char *);

int S::f(const char *p)
{
    char s[28];
    G1_func_00606b80(this, s);
    *(int *)this = 0xA93328;
    return (int)this;
}
