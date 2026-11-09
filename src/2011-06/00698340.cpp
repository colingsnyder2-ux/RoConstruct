// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00698340(void*);
extern int g_a_00698340;
extern int g_b_00698340;
extern int g_arg_00698340;
struct Reg_00698340 { Reg_00698340() { g_a_00698340 = 0; g_b_00698340 = 0; seh_fn_00698340(&g_arg_00698340); } };
void func_00698340()
{
    static Reg_00698340 reg;
}
