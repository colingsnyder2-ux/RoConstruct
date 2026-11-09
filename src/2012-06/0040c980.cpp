// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0040c980(void*);
extern int g_a_0040c980;
extern int g_b_0040c980;
extern int g_arg_0040c980;
struct Reg_0040c980 { Reg_0040c980() { g_a_0040c980 = 0; g_b_0040c980 = 0; seh_fn_0040c980(&g_arg_0040c980); } };
void func_0040c980()
{
    static Reg_0040c980 reg;
}
