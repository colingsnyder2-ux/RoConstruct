// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00500b30(void*);
extern int g_a_00500b30;
extern int g_b_00500b30;
extern int g_arg_00500b30;
struct Reg_00500b30 { Reg_00500b30() { g_a_00500b30 = 0; g_b_00500b30 = 0; seh_fn_00500b30(&g_arg_00500b30); } };
void func_00500b30()
{
    static Reg_00500b30 reg;
}
