// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00428850(void*);
extern int g_a_00428850;
extern int g_b_00428850;
extern int g_arg_00428850;
struct Reg_00428850 { Reg_00428850() { g_a_00428850 = 0; g_b_00428850 = 0; seh_fn_00428850(&g_arg_00428850); } };
void func_00428850()
{
    static Reg_00428850 reg;
}
