// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0048e150(void*);
extern int g_a_0048e150;
extern int g_b_0048e150;
extern int g_arg_0048e150;
struct Reg_0048e150 { Reg_0048e150() { g_a_0048e150 = 0; g_b_0048e150 = 0; seh_fn_0048e150(&g_arg_0048e150); } };
void func_0048e150()
{
    static Reg_0048e150 reg;
}
