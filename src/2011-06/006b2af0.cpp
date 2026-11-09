// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_006b2af0(void*);
extern int g_a_006b2af0;
extern int g_b_006b2af0;
extern int g_arg_006b2af0;
struct Reg_006b2af0 { Reg_006b2af0() { g_a_006b2af0 = 0; g_b_006b2af0 = 0; seh_fn_006b2af0(&g_arg_006b2af0); } };
void func_006b2af0()
{
    static Reg_006b2af0 reg;
}
