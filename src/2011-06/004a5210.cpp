// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004a5210(void*);
extern int g_a_004a5210;
extern int g_b_004a5210;
extern int g_arg_004a5210;
struct Reg_004a5210 { Reg_004a5210() { g_a_004a5210 = 0; g_b_004a5210 = 0; seh_fn_004a5210(&g_arg_004a5210); } };
void func_004a5210()
{
    static Reg_004a5210 reg;
}
