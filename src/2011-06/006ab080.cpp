// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_006ab080(void*);
extern int g_a_006ab080;
extern int g_b_006ab080;
extern int g_arg_006ab080;
struct Reg_006ab080 { Reg_006ab080() { g_a_006ab080 = 0; g_b_006ab080 = 0; seh_fn_006ab080(&g_arg_006ab080); } };
void func_006ab080()
{
    static Reg_006ab080 reg;
}
