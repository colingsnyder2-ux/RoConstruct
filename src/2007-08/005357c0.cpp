// from server: 100% by colin
extern "C" int __cdecl func_005bf350(int, int, int);
extern "C" int __cdecl func_005bf240(int, int, int);
extern "C" int __cdecl func_005c3730(int, int, int);

extern int G_func_008abe88;

int func_005357c0(int a)
{
    int v1 = func_005bf350(a, 2, 0);
    int v2 = func_005bf240(a, 1, G_func_008abe88);
    func_005c3730(v2, v1, a);
    return 0;
}
