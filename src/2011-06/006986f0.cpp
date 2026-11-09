// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_006986f0(void*);
extern int g_a_006986f0;
extern int g_b_006986f0;
extern int g_arg_006986f0;
struct Reg_006986f0 { Reg_006986f0() { g_a_006986f0 = 0; g_b_006986f0 = 0; seh_fn_006986f0(&g_arg_006986f0); } };
void func_006986f0()
{
    static Reg_006986f0 reg;
}
