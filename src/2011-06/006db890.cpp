// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_006db890(void*);
extern int g_a_006db890;
extern int g_b_006db890;
extern int g_arg_006db890;
struct Reg_006db890 { Reg_006db890() { g_a_006db890 = 0; g_b_006db890 = 0; seh_fn_006db890(&g_arg_006db890); } };
void func_006db890()
{
    static Reg_006db890 reg;
}
