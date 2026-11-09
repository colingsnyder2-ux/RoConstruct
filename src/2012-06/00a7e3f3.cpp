// from server: 40% by atomic.potato
extern "C" void __cdecl helper(int);
extern "C" void __stdcall target(float, int, float, int, float, int, int);

void __stdcall func_00a7e3f3(float a, int b, float c, int d, float e, int f, int g)
{
    helper(1);
    target(a, b, c, d, e, f, g);
}
