// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004ba450(void*);
extern int g_a_004ba450;
extern int g_b_004ba450;
extern int g_arg_004ba450;
struct Reg_004ba450 { Reg_004ba450() { g_a_004ba450 = 0; g_b_004ba450 = 0; seh_fn_004ba450(&g_arg_004ba450); } };
void func_004ba450()
{
    static Reg_004ba450 reg;
}
