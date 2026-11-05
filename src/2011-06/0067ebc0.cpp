// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0067ebc0(void*);
extern int g_a_0067ebc0;
extern int g_b_0067ebc0;
extern int g_arg_0067ebc0;
struct Reg_0067ebc0 { Reg_0067ebc0() { g_a_0067ebc0 = 0; g_b_0067ebc0 = 0; seh_fn_0067ebc0(&g_arg_0067ebc0); } };
void func_0067ebc0()
{
    static Reg_0067ebc0 reg;
}
