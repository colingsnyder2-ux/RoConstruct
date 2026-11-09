// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00428820(void*);
extern int g_a_00428820;
extern int g_b_00428820;
extern int g_arg_00428820;
struct Reg_00428820 { Reg_00428820() { g_a_00428820 = 0; g_b_00428820 = 0; seh_fn_00428820(&g_arg_00428820); } };
void func_00428820()
{
    static Reg_00428820 reg;
}
