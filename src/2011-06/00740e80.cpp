// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00740e80(void*);
extern int g_a_00740e80;
extern int g_b_00740e80;
extern int g_arg_00740e80;
struct Reg_00740e80 { Reg_00740e80() { g_a_00740e80 = 0; g_b_00740e80 = 0; seh_fn_00740e80(&g_arg_00740e80); } };
void func_00740e80()
{
    static Reg_00740e80 reg;
}
