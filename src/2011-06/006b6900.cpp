// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_006b6900(void*);
extern int g_a_006b6900;
extern int g_b_006b6900;
extern int g_arg_006b6900;
struct Reg_006b6900 { Reg_006b6900() { g_a_006b6900 = 0; g_b_006b6900 = 0; seh_fn_006b6900(&g_arg_006b6900); } };
void func_006b6900()
{
    static Reg_006b6900 reg;
}
