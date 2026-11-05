// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00666f60(void*);
extern int g_a_00666f60;
extern int g_b_00666f60;
extern int g_arg_00666f60;
struct Reg_00666f60 { Reg_00666f60() { g_a_00666f60 = 0; g_b_00666f60 = 0; seh_fn_00666f60(&g_arg_00666f60); } };
void func_00666f60()
{
    static Reg_00666f60 reg;
}
