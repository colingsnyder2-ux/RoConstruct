// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00437da0(void*);
extern int g_a_00437da0;
extern int g_b_00437da0;
extern int g_arg_00437da0;
struct Reg_00437da0 { Reg_00437da0() { g_a_00437da0 = 0; g_b_00437da0 = 0; seh_fn_00437da0(&g_arg_00437da0); } };
void func_00437da0()
{
    static Reg_00437da0 reg;
}
