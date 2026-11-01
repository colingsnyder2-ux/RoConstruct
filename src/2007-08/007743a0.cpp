// from server: 100% by colin
extern int g_007743a0_0;
extern int g_007743a0_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007743a0(void*);
struct O_007743a0 { int m(void*, void*, int, int); };
extern O_007743a0 g_obj_007743a0;
extern int g_tail_007743a0;
void func_007743a0()
{
    g_obj_007743a0.m((void*)&g_007743a0_0, (void*)&g_007743a0_1, 428, 5);
    tail_fn_007743a0(&g_tail_007743a0);
}