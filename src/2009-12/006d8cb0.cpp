// from server: 73% by atomic.potato
struct S
{
    int f();
};

extern "C" void G1_func_00466790(void *);
extern "C" void G1_func_006d7ae0(void *);

int S::f()
{
    G1_func_00466790((char *)this + 0xc0);
    G1_func_006d7ae0(this);
    return 0;
}
