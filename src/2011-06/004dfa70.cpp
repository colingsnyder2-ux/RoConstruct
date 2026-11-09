// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004dfa70(void*);
extern int g_a_004dfa70;
extern int g_b_004dfa70;
extern int g_arg_004dfa70;
struct Reg_004dfa70 { Reg_004dfa70() { g_a_004dfa70 = 0; g_b_004dfa70 = 0; seh_fn_004dfa70(&g_arg_004dfa70); } };
void func_004dfa70()
{
    static Reg_004dfa70 reg;
}
