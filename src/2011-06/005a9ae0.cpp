// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_005a9ae0(void*);
extern int g_a_005a9ae0;
extern int g_b_005a9ae0;
extern int g_arg_005a9ae0;
struct Reg_005a9ae0 { Reg_005a9ae0() { g_a_005a9ae0 = 0; g_b_005a9ae0 = 0; seh_fn_005a9ae0(&g_arg_005a9ae0); } };
void func_005a9ae0()
{
    static Reg_005a9ae0 reg;
}
