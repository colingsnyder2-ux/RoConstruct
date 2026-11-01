// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0047ce60(void*);
extern int g_a_0047ce60;
extern int g_b_0047ce60;
extern int g_arg_0047ce60;
struct Reg_0047ce60 { Reg_0047ce60() { g_a_0047ce60 = 0; g_b_0047ce60 = 0; seh_fn_0047ce60(&g_arg_0047ce60); } };
void func_0047ce60()
{
    static Reg_0047ce60 reg;
}
