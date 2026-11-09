// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_006d8700(void*);
extern int g_a_006d8700;
extern int g_b_006d8700;
extern int g_arg_006d8700;
struct Reg_006d8700 { Reg_006d8700() { g_a_006d8700 = 0; g_b_006d8700 = 0; seh_fn_006d8700(&g_arg_006d8700); } };
void func_006d8700()
{
    static Reg_006d8700 reg;
}
