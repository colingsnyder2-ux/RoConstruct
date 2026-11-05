// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00668620(void*);
extern int g_a_00668620;
extern int g_b_00668620;
extern int g_arg_00668620;
struct Reg_00668620 { Reg_00668620() { g_a_00668620 = 0; g_b_00668620 = 0; seh_fn_00668620(&g_arg_00668620); } };
void func_00668620()
{
    static Reg_00668620 reg;
}
