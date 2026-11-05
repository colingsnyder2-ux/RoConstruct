// from server: 96% by atomic.potato
struct S
{
    void f(void *);
};

extern "C" void __stdcall G1_func_006f9c80(void *, void *);

void S::f(void *arg)
{
    if (*(int *)((char *)this + 0x9c))
        G1_func_006f9c80(*(void **)((char *)this + 0x94), arg);
}
