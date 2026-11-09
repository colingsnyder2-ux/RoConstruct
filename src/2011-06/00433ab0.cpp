// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00433ab0(void*);
extern int g_a_00433ab0;
extern int g_b_00433ab0;
extern int g_arg_00433ab0;
struct Reg_00433ab0 { Reg_00433ab0() { g_a_00433ab0 = 0; g_b_00433ab0 = 0; seh_fn_00433ab0(&g_arg_00433ab0); } };
void func_00433ab0()
{
    static Reg_00433ab0 reg;
}
