// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_005dbf50(void*);
extern int g_a_005dbf50;
extern int g_b_005dbf50;
extern int g_arg_005dbf50;
struct Reg_005dbf50 { Reg_005dbf50() { g_a_005dbf50 = 0; g_b_005dbf50 = 0; seh_fn_005dbf50(&g_arg_005dbf50); } };
void func_005dbf50()
{
    static Reg_005dbf50 reg;
}
