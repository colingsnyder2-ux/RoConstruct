// from server: 75% by atomic.potato
struct S
{
    int f(void *);
    int *field;
};

extern "C" void G1_func_00917430(void *, void *);
extern "C" void G1_func_00925b60(int *, void *);

int S::f(void *arg)
{
    G1_func_00917430(arg, this);
    G1_func_00925b60(field, arg);
    return 0;
}
