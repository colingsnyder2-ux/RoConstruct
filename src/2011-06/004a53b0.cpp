// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004a53b0(void*);
extern int g_a_004a53b0;
extern int g_b_004a53b0;
extern int g_arg_004a53b0;
struct Reg_004a53b0 { Reg_004a53b0() { g_a_004a53b0 = 0; g_b_004a53b0 = 0; seh_fn_004a53b0(&g_arg_004a53b0); } };
void func_004a53b0()
{
    static Reg_004a53b0 reg;
}
