// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0042a030(void*);
extern int g_a_0042a030;
extern int g_b_0042a030;
extern int g_arg_0042a030;
struct Reg_0042a030 { Reg_0042a030() { g_a_0042a030 = 0; g_b_0042a030 = 0; seh_fn_0042a030(&g_arg_0042a030); } };
void func_0042a030()
{
    static Reg_0042a030 reg;
}
