// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_005e7c50(void*);
extern int g_a_005e7c50;
extern int g_b_005e7c50;
extern int g_arg_005e7c50;
struct Reg_005e7c50 { Reg_005e7c50() { g_a_005e7c50 = 0; g_b_005e7c50 = 0; seh_fn_005e7c50(&g_arg_005e7c50); } };
void func_005e7c50()
{
    static Reg_005e7c50 reg;
}
