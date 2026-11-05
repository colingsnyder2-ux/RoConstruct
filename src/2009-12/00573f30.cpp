// from server: 47% by atomic.potato
extern "C" void* __cdecl func_007f4a40(unsigned int);
extern "C" void __cdecl func_005739c0(int, int, int, int, int);
extern "C" void __cdecl func_00573c30(int, int, int, int, int, int, int);
extern "C" void __cdecl func_005731c0(int, int, int, int);

void func_00573f30(int a, int b, int c, int d, int e, int f, int g, int h)
{
    void* p = func_007f4a40((unsigned int)h * 4);
    func_005739c0(a, b, c, h, (int)p);
    func_00573c30(d, e, c, h, f, g, (int)p);
    func_005731c0(g, h, c, f);
}
