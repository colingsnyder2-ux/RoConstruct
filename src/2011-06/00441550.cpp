// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00441550(void*);
extern int g_a_00441550;
extern int g_b_00441550;
extern int g_arg_00441550;
struct Reg_00441550 { Reg_00441550() { g_a_00441550 = 0; g_b_00441550 = 0; seh_fn_00441550(&g_arg_00441550); } };
void func_00441550()
{
    static Reg_00441550 reg;
}
