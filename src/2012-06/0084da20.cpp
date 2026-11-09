// from server: 79% by atomic.potato
extern "C" {
    int __cdecl func_00831fd0(int, int);
    int __cdecl func_00832480(int, int);
    void __cdecl func_00832340(int, int, int);
    int __cdecl func_00831dc0(int, int, int);
    void __cdecl func_00831b00(int, int);
    int __cdecl func_006c1bf0();
    void __cdecl func_00575bc0(int, int);
}

extern unsigned int DAT_00de13e4;

bool __cdecl func_0084da20(int a, int b, int* out)
{
    int v = func_00831fd0(a, b);
    if (v == 0)
        return false;
    if (func_00832480(a, b) == 0)
        return false;
    func_00832340(a, -10000, DAT_00de13e4);
    if (func_00831dc0(a, -1, -2) != 0) {
        func_00831b00(a, -3);
        *out = func_006c1bf0();
        func_00575bc0((int)(out + 1), v);
        return true;
    }
    func_00831b00(a, -3);
    return false;
}
