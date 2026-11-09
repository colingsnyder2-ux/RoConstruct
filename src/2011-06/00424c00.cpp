// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00424c00(void*);
extern int g_a_00424c00;
extern int g_b_00424c00;
extern int g_arg_00424c00;
struct Reg_00424c00 { Reg_00424c00() { g_a_00424c00 = 0; g_b_00424c00 = 0; seh_fn_00424c00(&g_arg_00424c00); } };
void func_00424c00()
{
    static Reg_00424c00 reg;
}
