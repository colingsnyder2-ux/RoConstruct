// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_006d7e80(void*);
extern int g_a_006d7e80;
extern int g_b_006d7e80;
extern int g_arg_006d7e80;
struct Reg_006d7e80 { Reg_006d7e80() { g_a_006d7e80 = 0; g_b_006d7e80 = 0; seh_fn_006d7e80(&g_arg_006d7e80); } };
void func_006d7e80()
{
    static Reg_006d7e80 reg;
}
