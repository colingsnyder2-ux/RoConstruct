// from server: 83% by atomic.potato
extern "C" void __stdcall G1_func_00704e10(void *, void *, void *, float);

struct Handles
{
    void f(void *, float);
};

void Handles::f(void *a, float b)
{
    void *v = *(void **)((char *)this + 8);
    G1_func_00704e10(*(void **)((char *)this + 12), a,
                     v ? (void *)((char *)v + 28) : 0, b);
}
