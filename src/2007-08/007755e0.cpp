// from server: 100% by colin
extern int g_007755e0_0;
extern int g_007755e0_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007755e0(void*);
struct O_007755e0 { int m(void*, void*, int, int); };
extern O_007755e0 g_obj_007755e0;
extern int g_tail_007755e0;
void func_007755e0()
{
    g_obj_007755e0.m((void*)&g_007755e0_0, (void*)&g_007755e0_1, 252, 5);
    tail_fn_007755e0(&g_tail_007755e0);
}