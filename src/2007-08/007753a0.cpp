// from server: 100% by colin
extern int g_007753a0_0;
extern int g_007753a0_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007753a0(void*);
struct O_007753a0 { int m(void*, void*, int, int); };
extern O_007753a0 g_obj_007753a0;
extern int g_tail_007753a0;
void func_007753a0()
{
    g_obj_007753a0.m((void*)&g_007753a0_0, (void*)&g_007753a0_1, 292, 5);
    tail_fn_007753a0(&g_tail_007753a0);
}