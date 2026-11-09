// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_005f2270(void*);
extern int g_a_005f2270;
extern int g_b_005f2270;
extern int g_arg_005f2270;
struct Reg_005f2270 { Reg_005f2270() { g_a_005f2270 = 0; g_b_005f2270 = 0; seh_fn_005f2270(&g_arg_005f2270); } };
void func_005f2270()
{
    static Reg_005f2270 reg;
}
