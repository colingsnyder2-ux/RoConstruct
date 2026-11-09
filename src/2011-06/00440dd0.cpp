// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00440dd0(void*);
extern int g_a_00440dd0;
extern int g_b_00440dd0;
extern int g_arg_00440dd0;
struct Reg_00440dd0 { Reg_00440dd0() { g_a_00440dd0 = 0; g_b_00440dd0 = 0; seh_fn_00440dd0(&g_arg_00440dd0); } };
void func_00440dd0()
{
    static Reg_00440dd0 reg;
}
