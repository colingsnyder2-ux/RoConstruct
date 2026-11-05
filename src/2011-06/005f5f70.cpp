// from server: 62% by atomic.potato
extern "C" void __cdecl func_005f16e0(int, int, int, int, int, int);

int __stdcall func_005f5f70(int a, int b, int c)
{
    char local = 0;
    func_005f16e0(a, b, c, local, c, b);
    return b * 100 + a;
}
