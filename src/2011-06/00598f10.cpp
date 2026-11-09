// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00598f10(void*);
extern int g_a_00598f10;
extern int g_b_00598f10;
extern int g_arg_00598f10;
struct Reg_00598f10 { Reg_00598f10() { g_a_00598f10 = 0; g_b_00598f10 = 0; seh_fn_00598f10(&g_arg_00598f10); } };
void func_00598f10()
{
    static Reg_00598f10 reg;
}
