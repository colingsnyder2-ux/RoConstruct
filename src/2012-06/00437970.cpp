// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00437970(void*);
extern int g_a_00437970;
extern int g_b_00437970;
extern int g_arg_00437970;
struct Reg_00437970 { Reg_00437970() { g_a_00437970 = 0; g_b_00437970 = 0; seh_fn_00437970(&g_arg_00437970); } };
void func_00437970()
{
    static Reg_00437970 reg;
}
