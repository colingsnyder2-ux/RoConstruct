// from server: 32% by atomic.potato
extern "C" void __cdecl sub_008af41a(int);

extern "C" void __stdcall imported_call(
    int, int, int, int, int, float, int);

struct S
{
    void function_008aa20d(int, int, int, int, int, float, int);
};

void S::function_008aa20d(
    int a, int b, int c, int d, int e, float f, int g)
{
    sub_008af41a(1);
    imported_call(a, b, c, d, e, f, g);
}
