// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0073a9c0(void*);
extern int g_a_0073a9c0;
extern int g_b_0073a9c0;
extern int g_arg_0073a9c0;
struct Reg_0073a9c0 { Reg_0073a9c0() { g_a_0073a9c0 = 0; g_b_0073a9c0 = 0; seh_fn_0073a9c0(&g_arg_0073a9c0); } };
void func_0073a9c0()
{
    static Reg_0073a9c0 reg;
}
