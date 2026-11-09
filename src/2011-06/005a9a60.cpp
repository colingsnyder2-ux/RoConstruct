// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_005a9a60(void*);
extern int g_a_005a9a60;
extern int g_b_005a9a60;
extern int g_arg_005a9a60;
struct Reg_005a9a60 { Reg_005a9a60() { g_a_005a9a60 = 0; g_b_005a9a60 = 0; seh_fn_005a9a60(&g_arg_005a9a60); } };
void func_005a9a60()
{
    static Reg_005a9a60 reg;
}
