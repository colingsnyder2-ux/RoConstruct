// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00741650(void*);
extern int g_a_00741650;
extern int g_b_00741650;
extern int g_arg_00741650;
struct Reg_00741650 { Reg_00741650() { g_a_00741650 = 0; g_b_00741650 = 0; seh_fn_00741650(&g_arg_00741650); } };
void func_00741650()
{
    static Reg_00741650 reg;
}
