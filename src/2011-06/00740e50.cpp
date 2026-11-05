// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00740e50(void*);
extern int g_a_00740e50;
extern int g_b_00740e50;
extern int g_arg_00740e50;
struct Reg_00740e50 { Reg_00740e50() { g_a_00740e50 = 0; g_b_00740e50 = 0; seh_fn_00740e50(&g_arg_00740e50); } };
void func_00740e50()
{
    static Reg_00740e50 reg;
}
