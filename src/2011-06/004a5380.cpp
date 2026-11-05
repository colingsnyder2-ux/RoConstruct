// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004a5380(void*);
extern int g_a_004a5380;
extern int g_b_004a5380;
extern int g_arg_004a5380;
struct Reg_004a5380 { Reg_004a5380() { g_a_004a5380 = 0; g_b_004a5380 = 0; seh_fn_004a5380(&g_arg_004a5380); } };
void func_004a5380()
{
    static Reg_004a5380 reg;
}
