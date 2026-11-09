// from server: 100% by colin
extern "C" __declspec(dllimport) double _HUGE;

extern "C" int __cdecl func_005bf700(int, const char*, const char*);
extern "C" void __cdecl func_005bdb70(int, double);
extern "C" void __cdecl func_005be020(int, int, const char*);

extern double G_007b9d80;
extern double G_007b9d78;
extern double G_007b9d70;
extern double* G_0077e808;

int func_005c9ac0(int a)
{
    func_005bf700(a, "math", "@upper");
    func_005bdb70(a, G_007b9d80);
    func_005be020(a, -2, (const char*)&G_007b9d78);
    func_005bdb70(a, *G_0077e808);
    func_005be020(a, -2, (const char*)&G_007b9d70);
    return 1;
}
