// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0048dea0(void*);
extern int g_a_0048dea0;
extern int g_b_0048dea0;
extern int g_arg_0048dea0;
struct Reg_0048dea0 { Reg_0048dea0() { g_a_0048dea0 = 0; g_b_0048dea0 = 0; seh_fn_0048dea0(&g_arg_0048dea0); } };
void func_0048dea0()
{
    static Reg_0048dea0 reg;
}
