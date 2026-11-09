// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00471560(void*);
extern int g_a_00471560;
extern int g_b_00471560;
extern int g_arg_00471560;
struct Reg_00471560 { Reg_00471560() { g_a_00471560 = 0; g_b_00471560 = 0; seh_fn_00471560(&g_arg_00471560); } };
void func_00471560()
{
    static Reg_00471560 reg;
}
