// from server: 100% by colin
extern int g_00a2a730_0;
extern int g_00a2a730_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a2a730(void*);
struct O_00a2a730 { int m(void*, void*, int, int, int); };
extern O_00a2a730 g_obj_00a2a730;
extern int g_tail_00a2a730;
void func_00a2a730()
{
    g_obj_00a2a730.m((void*)&g_00a2a730_0, (void*)&g_00a2a730_1, 168, 31, 0);
    tail_fn_00a2a730(&g_tail_00a2a730);
}