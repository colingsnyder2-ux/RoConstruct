// from server: 48% by atomic.potato
extern "C" void G1_func_0076b2c0(void);
extern "C" void G1_func_006f4aa0(void *, void *);

struct S
{
    int f(void *);
};

int S::f(void *arg)
{
    G1_func_0076b2c0();
    G1_func_006f4aa0(*(void **)((char *)this + 0x94), arg);
    return (int)arg;
}
