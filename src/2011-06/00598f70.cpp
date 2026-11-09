// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00598f70(void*);
extern int g_a_00598f70;
extern int g_b_00598f70;
extern int g_arg_00598f70;
struct Reg_00598f70 { Reg_00598f70() { g_a_00598f70 = 0; g_b_00598f70 = 0; seh_fn_00598f70(&g_arg_00598f70); } };
void func_00598f70()
{
    static Reg_00598f70 reg;
}
