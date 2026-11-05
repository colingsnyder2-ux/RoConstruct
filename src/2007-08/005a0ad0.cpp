// from server: 100% by colin
struct S {
    char pad[0x280];
    int field_280;
    void func_005a0ad0(int);
};

extern int G_008c53d0;
extern void __stdcall G_func_00444710(int);

void S::func_005a0ad0(int arg)
{
    field_280 = arg;
    G_func_00444710((int)&G_008c53d0);
}
