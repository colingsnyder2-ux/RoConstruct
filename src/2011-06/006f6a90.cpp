// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_006f6a90(void*);
extern int g_a_006f6a90;
extern int g_b_006f6a90;
extern int g_arg_006f6a90;
struct Reg_006f6a90 { Reg_006f6a90() { g_a_006f6a90 = 0; g_b_006f6a90 = 0; seh_fn_006f6a90(&g_arg_006f6a90); } };
void func_006f6a90()
{
    static Reg_006f6a90 reg;
}
