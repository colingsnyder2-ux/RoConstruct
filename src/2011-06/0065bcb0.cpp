// from server: 65% by atomic.potato
extern "C" void G1_func_0065bbd0(void *, double, const char *);

struct S
{
    void f(int *);
};

void S::f(int *p)
{
    G1_func_0065bbd0(this, (double)*p, "D$<PQ");
}
