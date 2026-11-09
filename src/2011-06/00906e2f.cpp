// from server: 49% by atomic.potato
extern "C" void __cdecl sub_009092d5(int);

extern "C" void __stdcall imported_call(int, int, int, int, float);

struct S_func_00906e2f
{
    void f(int a, int b, int c, float d);
};

void S_func_00906e2f::f(int a, int b, int c, float d)
{
    sub_009092d5(1);
    imported_call(a, b, c, 0, d);
}
