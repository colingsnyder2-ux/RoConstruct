// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004e04c0(void*);
extern int g_a_004e04c0;
extern int g_b_004e04c0;
extern int g_arg_004e04c0;
struct Reg_004e04c0 { Reg_004e04c0() { g_a_004e04c0 = 0; g_b_004e04c0 = 0; seh_fn_004e04c0(&g_arg_004e04c0); } };
void func_004e04c0()
{
    static Reg_004e04c0 reg;
}
