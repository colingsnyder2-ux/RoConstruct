// from server: 53% by colin
extern "C" void __stdcall func_0070c9d0(int, int);
extern "C" void __stdcall func_0070d210();
extern "C" int __cdecl func_00630d60();

struct CXTColorLum
{
    void func_0070d240(int, char);
    void func_0070d210_helper();
    char pad[0x68];
    double field_68;
    char pad2[0x14];
    int field_84;
    int field_88;
};

void CXTColorLum::func_0070d240(int a, char b)
{
    func_0070c9d0(a, b);
    if (b)
    {
        int local[2];
        func_0070d210();
        int lo = local[0];
        int hi = local[1];
        int diff = hi - lo;
        double d = (double)diff * field_68;
        int rounded = func_00630d60();
        int result = hi - rounded - lo;
        field_88 = result;
        field_84 = result;
    }
}
