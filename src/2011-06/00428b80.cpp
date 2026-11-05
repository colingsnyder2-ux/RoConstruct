// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00428b80(void*);
extern int g_a_00428b80;
extern int g_b_00428b80;
extern int g_arg_00428b80;
struct Reg_00428b80 { Reg_00428b80() { g_a_00428b80 = 0; g_b_00428b80 = 0; seh_fn_00428b80(&g_arg_00428b80); } };
void func_00428b80()
{
    static Reg_00428b80 reg;
}
