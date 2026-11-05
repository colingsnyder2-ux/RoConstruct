// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_006d6850(void*);
extern int g_a_006d6850;
extern int g_b_006d6850;
extern int g_arg_006d6850;
struct Reg_006d6850 { Reg_006d6850() { g_a_006d6850 = 0; g_b_006d6850 = 0; seh_fn_006d6850(&g_arg_006d6850); } };
void func_006d6850()
{
    static Reg_006d6850 reg;
}
