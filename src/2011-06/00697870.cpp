// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00697870(void*);
extern int g_a_00697870;
extern int g_b_00697870;
extern int g_arg_00697870;
struct Reg_00697870 { Reg_00697870() { g_a_00697870 = 0; g_b_00697870 = 0; seh_fn_00697870(&g_arg_00697870); } };
void func_00697870()
{
    static Reg_00697870 reg;
}
