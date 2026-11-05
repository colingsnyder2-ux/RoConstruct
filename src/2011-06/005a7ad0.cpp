// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_005a7ad0(void*);
extern int g_a_005a7ad0;
extern int g_b_005a7ad0;
extern int g_arg_005a7ad0;
struct Reg_005a7ad0 { Reg_005a7ad0() { g_a_005a7ad0 = 0; g_b_005a7ad0 = 0; seh_fn_005a7ad0(&g_arg_005a7ad0); } };
void func_005a7ad0()
{
    static Reg_005a7ad0 reg;
}
