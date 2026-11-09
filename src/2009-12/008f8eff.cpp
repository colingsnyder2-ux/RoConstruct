// from server: 40% by atomic.potato
extern "C" void __stdcall func_008fb2b4(int);

extern "C" void (__stdcall *g_func)(int, int, int, int, float, float);

struct S
{
    void f(int, int, int, int, float, float);
};

void S::f(int a, int b, int c, int d, float e, float f)
{
    func_008fb2b4(1);
    g_func(a, b, c, d, e, f);
}
