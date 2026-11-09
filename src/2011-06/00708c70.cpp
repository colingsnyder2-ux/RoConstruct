// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00708c70(void*);
extern int g_a_00708c70;
extern int g_b_00708c70;
extern int g_arg_00708c70;
struct Reg_00708c70 { Reg_00708c70() { g_a_00708c70 = 0; g_b_00708c70 = 0; seh_fn_00708c70(&g_arg_00708c70); } };
void func_00708c70()
{
    static Reg_00708c70 reg;
}
