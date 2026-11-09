// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00681d90(void*);
extern int g_a_00681d90;
extern int g_b_00681d90;
extern int g_arg_00681d90;
struct Reg_00681d90 { Reg_00681d90() { g_a_00681d90 = 0; g_b_00681d90 = 0; seh_fn_00681d90(&g_arg_00681d90); } };
void func_00681d90()
{
    static Reg_00681d90 reg;
}
