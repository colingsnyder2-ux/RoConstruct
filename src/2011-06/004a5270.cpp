// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004a5270(void*);
extern int g_a_004a5270;
extern int g_b_004a5270;
extern int g_arg_004a5270;
struct Reg_004a5270 { Reg_004a5270() { g_a_004a5270 = 0; g_b_004a5270 = 0; seh_fn_004a5270(&g_arg_004a5270); } };
void func_004a5270()
{
    static Reg_004a5270 reg;
}
