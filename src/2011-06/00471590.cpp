// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00471590(void*);
extern int g_a_00471590;
extern int g_b_00471590;
extern int g_arg_00471590;
struct Reg_00471590 { Reg_00471590() { g_a_00471590 = 0; g_b_00471590 = 0; seh_fn_00471590(&g_arg_00471590); } };
void func_00471590()
{
    static Reg_00471590 reg;
}
