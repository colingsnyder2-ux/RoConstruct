// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004c8410(void*);
extern int g_a_004c8410;
extern int g_b_004c8410;
extern int g_arg_004c8410;
struct Reg_004c8410 { Reg_004c8410() { g_a_004c8410 = 0; g_b_004c8410 = 0; seh_fn_004c8410(&g_arg_004c8410); } };
void func_004c8410()
{
    static Reg_004c8410 reg;
}
