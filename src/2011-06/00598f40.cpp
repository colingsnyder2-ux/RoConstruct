// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00598f40(void*);
extern int g_a_00598f40;
extern int g_b_00598f40;
extern int g_arg_00598f40;
struct Reg_00598f40 { Reg_00598f40() { g_a_00598f40 = 0; g_b_00598f40 = 0; seh_fn_00598f40(&g_arg_00598f40); } };
void func_00598f40()
{
    static Reg_00598f40 reg;
}
