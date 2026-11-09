// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00704750(void*);
extern int g_a_00704750;
extern int g_b_00704750;
extern int g_arg_00704750;
struct Reg_00704750 { Reg_00704750() { g_a_00704750 = 0; g_b_00704750 = 0; seh_fn_00704750(&g_arg_00704750); } };
void func_00704750()
{
    static Reg_00704750 reg;
}
