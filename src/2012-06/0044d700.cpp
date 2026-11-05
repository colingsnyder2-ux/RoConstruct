// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0044d700(void*);
extern int g_a_0044d700;
extern int g_b_0044d700;
extern int g_arg_0044d700;
struct Reg_0044d700 { Reg_0044d700() { g_a_0044d700 = 0; g_b_0044d700 = 0; seh_fn_0044d700(&g_arg_0044d700); } };
void func_0044d700()
{
    static Reg_0044d700 reg;
}
