// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0047ce90(void*);
extern int g_a_0047ce90;
extern int g_b_0047ce90;
extern int g_arg_0047ce90;
struct Reg_0047ce90 { Reg_0047ce90() { g_a_0047ce90 = 0; g_b_0047ce90 = 0; seh_fn_0047ce90(&g_arg_0047ce90); } };
void func_0047ce90()
{
    static Reg_0047ce90 reg;
}
