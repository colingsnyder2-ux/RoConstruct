// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00437940(void*);
extern int g_a_00437940;
extern int g_b_00437940;
extern int g_arg_00437940;
struct Reg_00437940 { Reg_00437940() { g_a_00437940 = 0; g_b_00437940 = 0; seh_fn_00437940(&g_arg_00437940); } };
void func_00437940()
{
    static Reg_00437940 reg;
}
