// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00736a50(void*);
extern int g_a_00736a50;
extern int g_b_00736a50;
extern int g_arg_00736a50;
struct Reg_00736a50 { Reg_00736a50() { g_a_00736a50 = 0; g_b_00736a50 = 0; seh_fn_00736a50(&g_arg_00736a50); } };
void func_00736a50()
{
    static Reg_00736a50 reg;
}
