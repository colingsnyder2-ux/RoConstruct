// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00708a50(void*);
extern int g_a_00708a50;
extern int g_b_00708a50;
extern int g_arg_00708a50;
struct Reg_00708a50 { Reg_00708a50() { g_a_00708a50 = 0; g_b_00708a50 = 0; seh_fn_00708a50(&g_arg_00708a50); } };
void func_00708a50()
{
    static Reg_00708a50 reg;
}
