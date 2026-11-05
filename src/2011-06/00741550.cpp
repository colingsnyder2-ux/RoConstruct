// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00741550(void*);
extern int g_a_00741550;
extern int g_b_00741550;
extern int g_arg_00741550;
struct Reg_00741550 { Reg_00741550() { g_a_00741550 = 0; g_b_00741550 = 0; seh_fn_00741550(&g_arg_00741550); } };
void func_00741550()
{
    static Reg_00741550 reg;
}
