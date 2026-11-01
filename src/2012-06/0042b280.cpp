// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0042b280(void*);
extern int g_a_0042b280;
extern int g_b_0042b280;
extern int g_arg_0042b280;
struct Reg_0042b280 { Reg_0042b280() { g_a_0042b280 = 0; g_b_0042b280 = 0; seh_fn_0042b280(&g_arg_0042b280); } };
void func_0042b280()
{
    static Reg_0042b280 reg;
}
