// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_006dfb10(void*);
extern int g_a_006dfb10;
extern int g_b_006dfb10;
extern int g_arg_006dfb10;
struct Reg_006dfb10 { Reg_006dfb10() { g_a_006dfb10 = 0; g_b_006dfb10 = 0; seh_fn_006dfb10(&g_arg_006dfb10); } };
void func_006dfb10()
{
    static Reg_006dfb10 reg;
}
