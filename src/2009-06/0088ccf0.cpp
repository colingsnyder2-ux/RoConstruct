// from server: 100% by colin
extern int g_0088ccf0_0;
extern int g_0088ccf0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0088ccf0(void*);
struct O_0088ccf0 { int m(void*, void*, int, int); };
extern O_0088ccf0 g_obj_0088ccf0;
extern int g_tail_0088ccf0;
void func_0088ccf0()
{
    g_obj_0088ccf0.m((void*)&g_0088ccf0_0, (void*)&g_0088ccf0_1, 212, 7);
    tail_fn_0088ccf0(&g_tail_0088ccf0);
}