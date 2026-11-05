// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00681770(void*);
extern int g_a_00681770;
extern int g_b_00681770;
extern int g_arg_00681770;
struct Reg_00681770 { Reg_00681770() { g_a_00681770 = 0; g_b_00681770 = 0; seh_fn_00681770(&g_arg_00681770); } };
void func_00681770()
{
    static Reg_00681770 reg;
}
