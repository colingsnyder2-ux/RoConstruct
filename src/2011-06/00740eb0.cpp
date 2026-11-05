// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00740eb0(void*);
extern int g_a_00740eb0;
extern int g_b_00740eb0;
extern int g_arg_00740eb0;
struct Reg_00740eb0 { Reg_00740eb0() { g_a_00740eb0 = 0; g_b_00740eb0 = 0; seh_fn_00740eb0(&g_arg_00740eb0); } };
void func_00740eb0()
{
    static Reg_00740eb0 reg;
}
