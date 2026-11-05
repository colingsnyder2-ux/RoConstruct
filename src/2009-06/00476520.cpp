// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00476520(void*);
extern int g_a_00476520;
extern int g_b_00476520;
extern int g_arg_00476520;
struct Reg_00476520 { Reg_00476520() { g_a_00476520 = 0; g_b_00476520 = 0; seh_fn_00476520(&g_arg_00476520); } };
void func_00476520()
{
    static Reg_00476520 reg;
}
