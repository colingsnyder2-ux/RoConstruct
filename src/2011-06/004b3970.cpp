// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004b3970(void*);
extern int g_a_004b3970;
extern int g_b_004b3970;
extern int g_arg_004b3970;
struct Reg_004b3970 { Reg_004b3970() { g_a_004b3970 = 0; g_b_004b3970 = 0; seh_fn_004b3970(&g_arg_004b3970); } };
void func_004b3970()
{
    static Reg_004b3970 reg;
}
