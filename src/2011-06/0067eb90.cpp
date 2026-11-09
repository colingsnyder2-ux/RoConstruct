// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0067eb90(void*);
extern int g_a_0067eb90;
extern int g_b_0067eb90;
extern int g_arg_0067eb90;
struct Reg_0067eb90 { Reg_0067eb90() { g_a_0067eb90 = 0; g_b_0067eb90 = 0; seh_fn_0067eb90(&g_arg_0067eb90); } };
void func_0067eb90()
{
    static Reg_0067eb90 reg;
}
