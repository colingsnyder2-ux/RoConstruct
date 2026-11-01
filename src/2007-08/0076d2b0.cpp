// from server: 100% by colin
extern int g_0076d2b0_0;
extern int g_0076d2b0_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0076d2b0(void*);
struct O_0076d2b0 { int m(void*, void*, int, int); };
extern O_0076d2b0 g_obj_0076d2b0;
extern int g_tail_0076d2b0;
void func_0076d2b0()
{
    g_obj_0076d2b0.m((void*)&g_0076d2b0_0, (void*)&g_0076d2b0_1, 252, 4);
    tail_fn_0076d2b0(&g_tail_0076d2b0);
}