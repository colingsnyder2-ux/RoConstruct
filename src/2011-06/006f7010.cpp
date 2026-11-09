// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_006f7010(void*);
extern int g_a_006f7010;
extern int g_b_006f7010;
extern int g_arg_006f7010;
struct Reg_006f7010 { Reg_006f7010() { g_a_006f7010 = 0; g_b_006f7010 = 0; seh_fn_006f7010(&g_arg_006f7010); } };
void func_006f7010()
{
    static Reg_006f7010 reg;
}
