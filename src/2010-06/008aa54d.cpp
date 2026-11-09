// from server: 35% by atomic.potato
extern "C" void __cdecl func_008af41a(int);

extern "C" int __stdcall func_00bec140(
    int, int, int, int, int, int, float);

int __stdcall func_008aa54d(
    int a, int b, int c, int d, int e, int f, float g)
{
    func_008af41a(1);
    return func_00bec140(a, b, c, d, e, f, g);
}
