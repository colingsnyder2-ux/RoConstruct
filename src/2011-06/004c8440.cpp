// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004c8440(void*);
extern int g_a_004c8440;
extern int g_b_004c8440;
extern int g_arg_004c8440;
struct Reg_004c8440 { Reg_004c8440() { g_a_004c8440 = 0; g_b_004c8440 = 0; seh_fn_004c8440(&g_arg_004c8440); } };
void func_004c8440()
{
    static Reg_004c8440 reg;
}
