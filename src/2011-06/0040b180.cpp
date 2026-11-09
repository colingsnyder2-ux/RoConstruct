// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_0040b180(void*);
extern int g_a_0040b180;
extern int g_b_0040b180;
extern int g_arg_0040b180;
struct Reg_0040b180 { Reg_0040b180() { g_a_0040b180 = 0; g_b_0040b180 = 0; seh_fn_0040b180(&g_arg_0040b180); } };
void func_0040b180()
{
    static Reg_0040b180 reg;
}
