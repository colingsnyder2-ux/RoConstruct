// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004a5240(void*);
extern int g_a_004a5240;
extern int g_b_004a5240;
extern int g_arg_004a5240;
struct Reg_004a5240 { Reg_004a5240() { g_a_004a5240 = 0; g_b_004a5240 = 0; seh_fn_004a5240(&g_arg_004a5240); } };
void func_004a5240()
{
    static Reg_004a5240 reg;
}
