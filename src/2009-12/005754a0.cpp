// from server: 56% by atomic.potato
struct S
{
    void f();
};

extern "C" void G1_func_00575380(int);

void S::f()
{
    G1_func_00575380(*(int *)((char *)this + 4) + 4);
}
