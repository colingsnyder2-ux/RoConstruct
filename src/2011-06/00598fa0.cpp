// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00598fa0(void*);
extern int g_a_00598fa0;
extern int g_b_00598fa0;
extern int g_arg_00598fa0;
struct Reg_00598fa0 { Reg_00598fa0() { g_a_00598fa0 = 0; g_b_00598fa0 = 0; seh_fn_00598fa0(&g_arg_00598fa0); } };
void func_00598fa0()
{
    static Reg_00598fa0 reg;
}
