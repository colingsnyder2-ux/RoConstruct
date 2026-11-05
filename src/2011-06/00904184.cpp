// from server: 41% by atomic.potato
extern "C" void __cdecl sub_009092d5(int);

extern "C" void __stdcall imported_00C9B658(
    int, int, int, int, int, float);

struct S_func_00904184 {
    void f(int, int, int, int, int, float);
};

void S_func_00904184::f(int a, int b, int c, int d, int e, float value)
{
    sub_009092d5(1);
    imported_00C9B658(a, b, c, d, e, value);
}
