// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_007415d0(void*);
extern int g_a_007415d0;
extern int g_b_007415d0;
extern int g_arg_007415d0;
struct Reg_007415d0 { Reg_007415d0() { g_a_007415d0 = 0; g_b_007415d0 = 0; seh_fn_007415d0(&g_arg_007415d0); } };
void func_007415d0()
{
    static Reg_007415d0 reg;
}
