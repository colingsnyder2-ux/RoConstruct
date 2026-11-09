// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_006b6980(void*);
extern int g_a_006b6980;
extern int g_b_006b6980;
extern int g_arg_006b6980;
struct Reg_006b6980 { Reg_006b6980() { g_a_006b6980 = 0; g_b_006b6980 = 0; seh_fn_006b6980(&g_arg_006b6980); } };
void func_006b6980()
{
    static Reg_006b6980 reg;
}
