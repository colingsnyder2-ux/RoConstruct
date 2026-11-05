// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0061e2c0(void*);
extern int g_a_0061e2c0;
extern int g_b_0061e2c0;
extern int g_arg_0061e2c0;
struct Reg_0061e2c0 { Reg_0061e2c0() { g_a_0061e2c0 = 0; g_b_0061e2c0 = 0; seh_fn_0061e2c0(&g_arg_0061e2c0); } };
void func_0061e2c0()
{
    static Reg_0061e2c0 reg;
}
