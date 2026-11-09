// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00697b50(void*);
extern int g_a_00697b50;
extern int g_b_00697b50;
extern int g_arg_00697b50;
struct Reg_00697b50 { Reg_00697b50() { g_a_00697b50 = 0; g_b_00697b50 = 0; seh_fn_00697b50(&g_arg_00697b50); } };
void func_00697b50()
{
    static Reg_00697b50 reg;
}
