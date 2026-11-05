// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004252e0(void*);
extern int g_a_004252e0;
extern int g_b_004252e0;
extern int g_arg_004252e0;
struct Reg_004252e0 { Reg_004252e0() { g_a_004252e0 = 0; g_b_004252e0 = 0; seh_fn_004252e0(&g_arg_004252e0); } };
void func_004252e0()
{
    static Reg_004252e0 reg;
}
