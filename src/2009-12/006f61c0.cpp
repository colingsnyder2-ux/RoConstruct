// from server: 50% by atomic.potato
struct S
{
    void f();
};

extern "C" void G1_func_006f55a0(void *, void *);

void S::f()
{
    G1_func_006f55a0((char *)this + 4, (char *)this + 8);
}
