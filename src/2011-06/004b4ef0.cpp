// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004b4ef0(void*);
extern int g_a_004b4ef0;
extern int g_b_004b4ef0;
extern int g_arg_004b4ef0;
struct Reg_004b4ef0 { Reg_004b4ef0() { g_a_004b4ef0 = 0; g_b_004b4ef0 = 0; seh_fn_004b4ef0(&g_arg_004b4ef0); } };
void func_004b4ef0()
{
    static Reg_004b4ef0 reg;
}
