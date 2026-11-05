// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004b3090(void*);
extern int g_a_004b3090;
extern int g_b_004b3090;
extern int g_arg_004b3090;
struct Reg_004b3090 { Reg_004b3090() { g_a_004b3090 = 0; g_b_004b3090 = 0; seh_fn_004b3090(&g_arg_004b3090); } };
void func_004b3090()
{
    static Reg_004b3090 reg;
}
