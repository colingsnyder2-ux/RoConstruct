// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0092c8d0(void*);
extern int g_a_0092c8d0;
extern int g_b_0092c8d0;
extern int g_arg_0092c8d0;
struct Reg_0092c8d0 { Reg_0092c8d0() { g_a_0092c8d0 = 0; g_b_0092c8d0 = 0; seh_fn_0092c8d0(&g_arg_0092c8d0); } };
void func_0092c8d0()
{
    static Reg_0092c8d0 reg;
}
