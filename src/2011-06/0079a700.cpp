// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0079a700(void*);
extern int g_a_0079a700;
extern int g_b_0079a700;
extern int g_arg_0079a700;
struct Reg_0079a700 { Reg_0079a700() { g_a_0079a700 = 0; g_b_0079a700 = 0; seh_fn_0079a700(&g_arg_0079a700); } };
void func_0079a700()
{
    static Reg_0079a700 reg;
}
