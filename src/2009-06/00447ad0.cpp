// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00447ad0(void*);
extern int g_a_00447ad0;
extern int g_b_00447ad0;
extern int g_arg_00447ad0;
struct Reg_00447ad0 { Reg_00447ad0() { g_a_00447ad0 = 0; g_b_00447ad0 = 0; seh_fn_00447ad0(&g_arg_00447ad0); } };
void func_00447ad0()
{
    static Reg_00447ad0 reg;
}
