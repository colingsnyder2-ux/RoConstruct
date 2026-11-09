// from server: 44% by colin
struct CRobloxDHtmlDialog {
    void func_0044cd90(int, int, int, int, int, int, int);
};

extern "C" int __stdcall G1_func_0077dd90(int);
extern "C" int __stdcall G1_func_0077dd98();
extern "C" int __stdcall G1_func_0077ddbc();
extern int G1_func_0041bd60(int);

void CRobloxDHtmlDialog::func_0044cd90(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    int local;
    int result;
    int v1;
    int v2;

    G1_func_0077dd90(*(int*)(a1 + 8));
    result = G1_func_0077dd98();
    local = 0;
    if (G1_func_0041bd60(result)) {
        *(int*)a7 = 1;
    } else {
        v1 = *(int*)this;
        v2 = G1_func_0077dd98();
        (*(void (__thiscall**)(CRobloxDHtmlDialog*, int, int))(v1 + 0x168))(this, v2, local);
    }
    G1_func_0077ddbc();
}
