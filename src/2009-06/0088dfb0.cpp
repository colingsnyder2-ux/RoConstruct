// from server: 100% by colin
extern int g_0088dfb0_0;
extern int g_0088dfb0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0088dfb0(void*);
struct O_0088dfb0 { int m(void*, void*, int, int); };
extern O_0088dfb0 g_obj_0088dfb0;
extern int g_tail_0088dfb0;
void func_0088dfb0()
{
    g_obj_0088dfb0.m((void*)&g_0088dfb0_0, (void*)&g_0088dfb0_1, 140, 7);
    tail_fn_0088dfb0(&g_tail_0088dfb0);
}