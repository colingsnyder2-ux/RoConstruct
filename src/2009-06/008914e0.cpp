// from server: 100% by colin
extern int g_008914e0_0;
extern int g_008914e0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_008914e0(void*);
struct O_008914e0 { int m(void*, void*, int, int); };
extern O_008914e0 g_obj_008914e0;
extern int g_tail_008914e0;
void func_008914e0()
{
    g_obj_008914e0.m((void*)&g_008914e0_0, (void*)&g_008914e0_1, 416, 7);
    tail_fn_008914e0(&g_tail_008914e0);
}