// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00704720(void*);
extern int g_a_00704720;
extern int g_b_00704720;
extern int g_arg_00704720;
struct Reg_00704720 { Reg_00704720() { g_a_00704720 = 0; g_b_00704720 = 0; seh_fn_00704720(&g_arg_00704720); } };
void func_00704720()
{
    static Reg_00704720 reg;
}
