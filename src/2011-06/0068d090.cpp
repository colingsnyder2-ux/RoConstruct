// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0068d090(void*);
extern int g_a_0068d090;
extern int g_b_0068d090;
extern int g_arg_0068d090;
struct Reg_0068d090 { Reg_0068d090() { g_a_0068d090 = 0; g_b_0068d090 = 0; seh_fn_0068d090(&g_arg_0068d090); } };
void func_0068d090()
{
    static Reg_0068d090 reg;
}
