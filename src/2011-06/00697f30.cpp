// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00697f30(void*);
extern int g_a_00697f30;
extern int g_b_00697f30;
extern int g_arg_00697f30;
struct Reg_00697f30 { Reg_00697f30() { g_a_00697f30 = 0; g_b_00697f30 = 0; seh_fn_00697f30(&g_arg_00697f30); } };
void func_00697f30()
{
    static Reg_00697f30 reg;
}
