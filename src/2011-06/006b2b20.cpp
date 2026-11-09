// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_006b2b20(void*);
extern int g_a_006b2b20;
extern int g_b_006b2b20;
extern int g_arg_006b2b20;
struct Reg_006b2b20 { Reg_006b2b20() { g_a_006b2b20 = 0; g_b_006b2b20 = 0; seh_fn_006b2b20(&g_arg_006b2b20); } };
void func_006b2b20()
{
    static Reg_006b2b20 reg;
}
