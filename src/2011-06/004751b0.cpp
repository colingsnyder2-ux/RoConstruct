// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004751b0(void*);
extern int g_a_004751b0;
extern int g_b_004751b0;
extern int g_arg_004751b0;
struct Reg_004751b0 { Reg_004751b0() { g_a_004751b0 = 0; g_b_004751b0 = 0; seh_fn_004751b0(&g_arg_004751b0); } };
void func_004751b0()
{
    static Reg_004751b0 reg;
}
