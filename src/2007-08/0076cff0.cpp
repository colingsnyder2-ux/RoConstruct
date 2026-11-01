// from server: 100% by colin
extern int g_0076cff0_0;
extern int g_0076cff0_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0076cff0(void*);
struct O_0076cff0 { int m(void*, void*, int, int); };
extern O_0076cff0 g_obj_0076cff0;
extern int g_tail_0076cff0;
void func_0076cff0()
{
    g_obj_0076cff0.m((void*)&g_0076cff0_0, (void*)&g_0076cff0_1, 268, 5);
    tail_fn_0076cff0(&g_tail_0076cff0);
}