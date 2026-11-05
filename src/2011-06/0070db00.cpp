// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0070db00(void*);
extern int g_a_0070db00;
extern int g_b_0070db00;
extern int g_arg_0070db00;
struct Reg_0070db00 { Reg_0070db00() { g_a_0070db00 = 0; g_b_0070db00 = 0; seh_fn_0070db00(&g_arg_0070db00); } };
void func_0070db00()
{
    static Reg_0070db00 reg;
}
