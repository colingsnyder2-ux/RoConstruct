// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_004c8470(void*);
extern int g_a_004c8470;
extern int g_b_004c8470;
extern int g_arg_004c8470;
struct Reg_004c8470 { Reg_004c8470() { g_a_004c8470 = 0; g_b_004c8470 = 0; seh_fn_004c8470(&g_arg_004c8470); } };
void func_004c8470()
{
    static Reg_004c8470 reg;
}
