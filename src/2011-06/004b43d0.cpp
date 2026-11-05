// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004b43d0(void*);
extern int g_a_004b43d0;
extern int g_b_004b43d0;
extern int g_arg_004b43d0;
struct Reg_004b43d0 { Reg_004b43d0() { g_a_004b43d0 = 0; g_b_004b43d0 = 0; seh_fn_004b43d0(&g_arg_004b43d0); } };
void func_004b43d0()
{
    static Reg_004b43d0 reg;
}
