// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00475230(void*);
extern int g_a_00475230;
extern int g_b_00475230;
extern int g_arg_00475230;
struct Reg_00475230 { Reg_00475230() { g_a_00475230 = 0; g_b_00475230 = 0; seh_fn_00475230(&g_arg_00475230); } };
void func_00475230()
{
    static Reg_00475230 reg;
}
