// from server: 65% by atomic.potato
struct S
{
    int f(const char *);
};

extern "C" void G1_func_00606b80(S *);
extern "C" void G2_func_00a404c4(void *, const char *);

int S::f(const char *value)
{
    G2_func_00a404c4(this, value);
    G1_func_00606b80(this);
    *(int *)this = 0x00a9329c;
    return (int)this;
}
