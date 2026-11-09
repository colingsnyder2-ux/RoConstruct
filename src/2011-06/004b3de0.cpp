// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004b3de0(void*);
extern int g_a_004b3de0;
extern int g_b_004b3de0;
extern int g_arg_004b3de0;
struct Reg_004b3de0 { Reg_004b3de0() { g_a_004b3de0 = 0; g_b_004b3de0 = 0; seh_fn_004b3de0(&g_arg_004b3de0); } };
void func_004b3de0()
{
    static Reg_004b3de0 reg;
}
