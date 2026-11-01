// from server: 100% by colin
extern int g_008917c0_0;
extern int g_008917c0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_008917c0(void*);
struct O_008917c0 { int m(void*, void*, int, int); };
extern O_008917c0 g_obj_008917c0;
extern int g_tail_008917c0;
void func_008917c0()
{
    g_obj_008917c0.m((void*)&g_008917c0_0, (void*)&g_008917c0_1, 340, 7);
    tail_fn_008917c0(&g_tail_008917c0);
}