// from server: 50% by atomic.potato
extern "C" void __cdecl func_008af41a(int);

extern "C" void __stdcall func_00bec124(int, int, float);

struct S
{
    void f(int, int, float);
};

void S::f(int a, int b, float c)
{
    func_008af41a(1);
    func_00bec124(a, b, c);
}
