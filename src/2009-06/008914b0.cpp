// from server: 100% by colin
extern int g_008914b0_0;
extern int g_008914b0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_008914b0(void*);
struct O_008914b0 { int m(void*, void*, int, int); };
extern O_008914b0 g_obj_008914b0;
extern int g_tail_008914b0;
void func_008914b0()
{
    g_obj_008914b0.m((void*)&g_008914b0_0, (void*)&g_008914b0_1, 404, 7);
    tail_fn_008914b0(&g_tail_008914b0);
}