// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004ba680(void*);
extern int g_a_004ba680;
extern int g_b_004ba680;
extern int g_arg_004ba680;
struct Reg_004ba680 { Reg_004ba680() { g_a_004ba680 = 0; g_b_004ba680 = 0; seh_fn_004ba680(&g_arg_004ba680); } };
void func_004ba680()
{
    static Reg_004ba680 reg;
}
