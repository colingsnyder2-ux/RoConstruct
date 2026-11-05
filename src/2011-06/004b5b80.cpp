// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004b5b80(void*);
extern int g_a_004b5b80;
extern int g_b_004b5b80;
extern int g_arg_004b5b80;
struct Reg_004b5b80 { Reg_004b5b80() { g_a_004b5b80 = 0; g_b_004b5b80 = 0; seh_fn_004b5b80(&g_arg_004b5b80); } };
void func_004b5b80()
{
    static Reg_004b5b80 reg;
}
