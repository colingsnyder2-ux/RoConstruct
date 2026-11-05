// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00427470(void*);
extern int g_a_00427470;
extern int g_b_00427470;
extern int g_arg_00427470;
struct Reg_00427470 { Reg_00427470() { g_a_00427470 = 0; g_b_00427470 = 0; seh_fn_00427470(&g_arg_00427470); } };
void func_00427470()
{
    static Reg_00427470 reg;
}
