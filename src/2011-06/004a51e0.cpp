// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004a51e0(void*);
extern int g_a_004a51e0;
extern int g_b_004a51e0;
extern int g_arg_004a51e0;
struct Reg_004a51e0 { Reg_004a51e0() { g_a_004a51e0 = 0; g_b_004a51e0 = 0; seh_fn_004a51e0(&g_arg_004a51e0); } };
void func_004a51e0()
{
    static Reg_004a51e0 reg;
}
