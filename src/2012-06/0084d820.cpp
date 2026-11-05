// from server: 79% by atomic.potato
extern "C" int __cdecl func_00831fd0(int, int);
extern "C" int __cdecl func_00832480(int, int);
extern "C" void __cdecl func_00832340(int, int, unsigned int);
extern "C" int __cdecl func_00831dc0(int, int, int);
extern "C" void __cdecl func_00831b00(int, int);
extern "C" int __cdecl func_006c21c0();
extern "C" void __cdecl func_00520fd0(int*, int);

extern unsigned int DAT_00de13d0;

bool func_0084d820(int a, int b, int* out)
{
    int v = func_00831fd0(a, b);
    if (v == 0)
        return false;
    if (func_00832480(a, b) == 0)
        return false;
    func_00832340(a, -10000, DAT_00de13d0);
    int r = func_00831dc0(a, -1, -2);
    if (r != 0)
    {
        func_00831b00(a, -3);
        *out = func_006c21c0();
        func_00520fd0(out + 1, v);
        return true;
    }
    func_00831b00(a, -3);
    return false;
}
