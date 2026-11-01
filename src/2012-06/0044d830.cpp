// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0044d830(void*);
extern int g_a_0044d830;
extern int g_b_0044d830;
extern int g_arg_0044d830;
struct Reg_0044d830 { Reg_0044d830() { g_a_0044d830 = 0; g_b_0044d830 = 0; seh_fn_0044d830(&g_arg_0044d830); } };
void func_0044d830()
{
    static Reg_0044d830 reg;
}
