// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00704d60(void*);
extern int g_a_00704d60;
extern int g_b_00704d60;
extern int g_arg_00704d60;
struct Reg_00704d60 { Reg_00704d60() { g_a_00704d60 = 0; g_b_00704d60 = 0; seh_fn_00704d60(&g_arg_00704d60); } };
void func_00704d60()
{
    static Reg_00704d60 reg;
}
