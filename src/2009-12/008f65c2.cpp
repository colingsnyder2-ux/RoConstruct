// from server: 40% by atomic.potato
extern "C" void __stdcall sub_008fb2b4(int);

extern "C" void __stdcall imported_call(
    int, int, int, int, float, float, int);

void __stdcall func_008f65c2(
    int a, int b, int c, int d, float e, float f)
{
    sub_008fb2b4(1);
    imported_call(a, b, c, d, e, f, 0);
}
