// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0042b230(void*);
extern int g_a_0042b230;
extern int g_b_0042b230;
extern int g_arg_0042b230;
struct Reg_0042b230 { Reg_0042b230() { g_a_0042b230 = 0; g_b_0042b230 = 0; seh_fn_0042b230(&g_arg_0042b230); } };
void func_0042b230()
{
    static Reg_0042b230 reg;
}
