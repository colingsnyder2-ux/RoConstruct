// from server: 100% by colin
extern int g_00a2b730_0;
extern int g_00a2b730_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a2b730(void*);
struct O_00a2b730 { int m(void*, void*, int, int, int); };
extern O_00a2b730 g_obj_00a2b730;
extern int g_tail_00a2b730;
void func_00a2b730()
{
    g_obj_00a2b730.m((void*)&g_00a2b730_0, (void*)&g_00a2b730_1, 376, 31, 0);
    tail_fn_00a2b730(&g_tail_00a2b730);
}