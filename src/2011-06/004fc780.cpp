// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004fc780(void*);
extern int g_a_004fc780;
extern int g_b_004fc780;
extern int g_arg_004fc780;
struct Reg_004fc780 { Reg_004fc780() { g_a_004fc780 = 0; g_b_004fc780 = 0; seh_fn_004fc780(&g_arg_004fc780); } };
void func_004fc780()
{
    static Reg_004fc780 reg;
}
