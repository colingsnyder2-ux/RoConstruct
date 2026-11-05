// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00432290(void*);
extern int g_a_00432290;
extern int g_b_00432290;
extern int g_arg_00432290;
struct Reg_00432290 { Reg_00432290() { g_a_00432290 = 0; g_b_00432290 = 0; seh_fn_00432290(&g_arg_00432290); } };
void func_00432290()
{
    static Reg_00432290 reg;
}
