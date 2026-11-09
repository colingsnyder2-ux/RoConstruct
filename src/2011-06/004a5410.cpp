// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004a5410(void*);
extern int g_a_004a5410;
extern int g_b_004a5410;
extern int g_arg_004a5410;
struct Reg_004a5410 { Reg_004a5410() { g_a_004a5410 = 0; g_b_004a5410 = 0; seh_fn_004a5410(&g_arg_004a5410); } };
void func_004a5410()
{
    static Reg_004a5410 reg;
}
