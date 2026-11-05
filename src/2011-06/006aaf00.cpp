// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_006aaf00(void*);
extern int g_a_006aaf00;
extern int g_b_006aaf00;
extern int g_arg_006aaf00;
struct Reg_006aaf00 { Reg_006aaf00() { g_a_006aaf00 = 0; g_b_006aaf00 = 0; seh_fn_006aaf00(&g_arg_006aaf00); } };
void func_006aaf00()
{
    static Reg_006aaf00 reg;
}
