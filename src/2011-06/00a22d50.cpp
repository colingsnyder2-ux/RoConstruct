// from server: 100% by colin
extern int g_00a22d50_0;
extern int g_00a22d50_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a22d50(void*);
struct O_00a22d50 { int m(void*, void*, int, int, int); };
extern O_00a22d50 g_obj_00a22d50;
extern int g_tail_00a22d50;
void func_00a22d50()
{
    g_obj_00a22d50.m((void*)&g_00a22d50_0, (void*)&g_00a22d50_1, 536, 2, 0);
    tail_fn_00a22d50(&g_tail_00a22d50);
}