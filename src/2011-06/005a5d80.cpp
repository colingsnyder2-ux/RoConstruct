// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_005a5d80(void*);
extern int g_a_005a5d80;
extern int g_b_005a5d80;
extern int g_arg_005a5d80;
struct Reg_005a5d80 { Reg_005a5d80() { g_a_005a5d80 = 0; g_b_005a5d80 = 0; seh_fn_005a5d80(&g_arg_005a5d80); } };
void func_005a5d80()
{
    static Reg_005a5d80 reg;
}
