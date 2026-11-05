// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0061a0a0(void*);
extern int g_a_0061a0a0;
extern int g_b_0061a0a0;
extern int g_arg_0061a0a0;
struct Reg_0061a0a0 { Reg_0061a0a0() { g_a_0061a0a0 = 0; g_b_0061a0a0 = 0; seh_fn_0061a0a0(&g_arg_0061a0a0); } };
void func_0061a0a0()
{
    static Reg_0061a0a0 reg;
}
