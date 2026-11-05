// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_00708490(void*);
extern int g_a_00708490;
extern int g_b_00708490;
extern int g_arg_00708490;
struct Reg_00708490 { Reg_00708490() { g_a_00708490 = 0; g_b_00708490 = 0; seh_fn_00708490(&g_arg_00708490); } };
void func_00708490()
{
    static Reg_00708490 reg;
}
