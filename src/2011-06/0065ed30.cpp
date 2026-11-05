// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0065ed30(void*);
extern int g_a_0065ed30;
extern int g_b_0065ed30;
extern int g_arg_0065ed30;
struct Reg_0065ed30 { Reg_0065ed30() { g_a_0065ed30 = 0; g_b_0065ed30 = 0; seh_fn_0065ed30(&g_arg_0065ed30); } };
void func_0065ed30()
{
    static Reg_0065ed30 reg;
}
