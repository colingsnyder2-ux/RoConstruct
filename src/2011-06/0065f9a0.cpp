// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0065f9a0(void*);
extern int g_a_0065f9a0;
extern int g_b_0065f9a0;
extern int g_arg_0065f9a0;
struct Reg_0065f9a0 { Reg_0065f9a0() { g_a_0065f9a0 = 0; g_b_0065f9a0 = 0; seh_fn_0065f9a0(&g_arg_0065f9a0); } };
void func_0065f9a0()
{
    static Reg_0065f9a0 reg;
}
