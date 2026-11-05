// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_006d70e0(void*);
extern int g_a_006d70e0;
extern int g_b_006d70e0;
extern int g_arg_006d70e0;
struct Reg_006d70e0 { Reg_006d70e0() { g_a_006d70e0 = 0; g_b_006d70e0 = 0; seh_fn_006d70e0(&g_arg_006d70e0); } };
void func_006d70e0()
{
    static Reg_006d70e0 reg;
}
