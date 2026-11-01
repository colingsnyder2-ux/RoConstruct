// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004ba650(void*);
extern int g_a_004ba650;
extern int g_b_004ba650;
extern int g_arg_004ba650;
struct Reg_004ba650 { Reg_004ba650() { g_a_004ba650 = 0; g_b_004ba650 = 0; seh_fn_004ba650(&g_arg_004ba650); } };
void func_004ba650()
{
    static Reg_004ba650 reg;
}
