// from server: 62% by atomic.potato
struct S_func_0051dfb0
{
    char padding[0x1f0];
    double value;
    void f(void *a, void *b);
};

extern "C" void __cdecl func_007fddb0(double, void *, void *);

void S_func_0051dfb0::f(void *a, void *b)
{
    func_007fddb0(value, a, b);
}
