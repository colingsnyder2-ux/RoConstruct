// from server: 40% by atomic.potato
extern "C" void __stdcall sub_a814d5(int);

extern "C" void __stdcall imported_call(int, float, int, int, int);

void __stdcall function_00a7e71f(int a, float b, int c, int d, int e)
{
    sub_a814d5(1);
    imported_call(a, b, c, d, e);
}
