// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004f52a0(void*);
extern int g_a_004f52a0;
extern int g_b_004f52a0;
extern int g_arg_004f52a0;
struct Reg_004f52a0 { Reg_004f52a0() { g_a_004f52a0 = 0; g_b_004f52a0 = 0; seh_fn_004f52a0(&g_arg_004f52a0); } };
void func_004f52a0()
{
    static Reg_004f52a0 reg;
}
