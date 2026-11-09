// from server: 100% by colin
extern int g_007742e0_0;
extern int g_007742e0_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007742e0(void*);
struct O_007742e0 { int m(void*, void*, int, int); };
extern O_007742e0 g_obj_007742e0;
extern int g_tail_007742e0;
void func_007742e0()
{
    g_obj_007742e0.m((void*)&g_007742e0_0, (void*)&g_007742e0_1, 296, 5);
    tail_fn_007742e0(&g_tail_007742e0);
}