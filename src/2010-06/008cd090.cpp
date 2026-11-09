// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_008cd090(void*);
extern int g_a_008cd090;
extern int g_b_008cd090;
extern int g_arg_008cd090;
struct Reg_008cd090 { Reg_008cd090() { g_a_008cd090 = 0; g_b_008cd090 = 0; seh_fn_008cd090(&g_arg_008cd090); } };
void func_008cd090()
{
    static Reg_008cd090 reg;
}
