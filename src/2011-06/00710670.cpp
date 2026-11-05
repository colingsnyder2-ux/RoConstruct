// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00710670(void*);
extern int g_a_00710670;
extern int g_b_00710670;
extern int g_arg_00710670;
struct Reg_00710670 { Reg_00710670() { g_a_00710670 = 0; g_b_00710670 = 0; seh_fn_00710670(&g_arg_00710670); } };
void func_00710670()
{
    static Reg_00710670 reg;
}
