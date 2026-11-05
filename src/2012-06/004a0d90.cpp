// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004a0d90(void*);
extern int g_a_004a0d90;
extern int g_b_004a0d90;
extern int g_arg_004a0d90;
struct Reg_004a0d90 { Reg_004a0d90() { g_a_004a0d90 = 0; g_b_004a0d90 = 0; seh_fn_004a0d90(&g_arg_004a0d90); } };
void func_004a0d90()
{
    static Reg_004a0d90 reg;
}
