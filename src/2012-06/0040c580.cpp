// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0040c580(void*);
extern int g_a_0040c580;
extern int g_b_0040c580;
extern int g_arg_0040c580;
struct Reg_0040c580 { Reg_0040c580() { g_a_0040c580 = 0; g_b_0040c580 = 0; seh_fn_0040c580(&g_arg_0040c580); } };
void func_0040c580()
{
    static Reg_0040c580 reg;
}
