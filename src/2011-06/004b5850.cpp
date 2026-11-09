// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004b5850(void*);
extern int g_a_004b5850;
extern int g_b_004b5850;
extern int g_arg_004b5850;
struct Reg_004b5850 { Reg_004b5850() { g_a_004b5850 = 0; g_b_004b5850 = 0; seh_fn_004b5850(&g_arg_004b5850); } };
void func_004b5850()
{
    static Reg_004b5850 reg;
}
