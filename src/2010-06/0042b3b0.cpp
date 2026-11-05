// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0042b3b0(void*);
extern int g_a_0042b3b0;
extern int g_b_0042b3b0;
extern int g_arg_0042b3b0;
struct Reg_0042b3b0 { Reg_0042b3b0() { g_a_0042b3b0 = 0; g_b_0042b3b0 = 0; seh_fn_0042b3b0(&g_arg_0042b3b0); } };
void func_0042b3b0()
{
    static Reg_0042b3b0 reg;
}
