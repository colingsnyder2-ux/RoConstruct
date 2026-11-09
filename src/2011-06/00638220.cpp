// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00638220(void*);
extern int g_a_00638220;
extern int g_b_00638220;
extern int g_arg_00638220;
struct Reg_00638220 { Reg_00638220() { g_a_00638220 = 0; g_b_00638220 = 0; seh_fn_00638220(&g_arg_00638220); } };
void func_00638220()
{
    static Reg_00638220 reg;
}
