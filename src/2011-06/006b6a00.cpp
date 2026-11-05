// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_006b6a00(void*);
extern int g_a_006b6a00;
extern int g_b_006b6a00;
extern int g_arg_006b6a00;
struct Reg_006b6a00 { Reg_006b6a00() { g_a_006b6a00 = 0; g_b_006b6a00 = 0; seh_fn_006b6a00(&g_arg_006b6a00); } };
void func_006b6a00()
{
    static Reg_006b6a00 reg;
}
