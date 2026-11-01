// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00439380(void*);
extern int g_a_00439380;
extern int g_b_00439380;
extern int g_arg_00439380;
struct Reg_00439380 { Reg_00439380() { g_a_00439380 = 0; g_b_00439380 = 0; seh_fn_00439380(&g_arg_00439380); } };
void func_00439380()
{
    static Reg_00439380 reg;
}
