// from server: 90% by atomic.potato
struct S
{
    void f();
};

extern "C" void G1_func_004a6690(void *);

void S::f()
{
    void *p = (void *)0x005b71f0;
    G1_func_004a6690(&p);
}
