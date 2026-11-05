// from server: 57% by atomic.potato
extern "C" void __cdecl func_008fb2b4(int);

extern "C" void (__stdcall *func_00b6b33c)(float, float);

struct S
{
    void f(float, float);
};

void S::f(float a, float b)
{
    func_008fb2b4(1);
    func_00b6b33c(a, b);
}
