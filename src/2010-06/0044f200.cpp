// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0044f200(void*);
extern int g_a_0044f200;
extern int g_b_0044f200;
extern int g_arg_0044f200;
struct Reg_0044f200 { Reg_0044f200() { g_a_0044f200 = 0; g_b_0044f200 = 0; seh_fn_0044f200(&g_arg_0044f200); } };
void func_0044f200()
{
    static Reg_0044f200 reg;
}
