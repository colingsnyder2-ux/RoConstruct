// from server: 55% by atomic.potato
extern "C" void __cdecl G1_func_00410330(void *, void *);
extern "C" void G1_func_00560050(void *);

struct S
{
    int f(void *);
};

int S::f(void *arg)
{
    void *local;
    G1_func_00410330(&local, arg);
    G1_func_00560050(this);
    return 0;
}
