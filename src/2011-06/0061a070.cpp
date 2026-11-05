// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0061a070(void*);
extern int g_a_0061a070;
extern int g_b_0061a070;
extern int g_arg_0061a070;
struct Reg_0061a070 { Reg_0061a070() { g_a_0061a070 = 0; g_b_0061a070 = 0; seh_fn_0061a070(&g_arg_0061a070); } };
void func_0061a070()
{
    static Reg_0061a070 reg;
}
