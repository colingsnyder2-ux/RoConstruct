// from server: 100% by colin
extern int g_00a2b060_1;
extern int g_00a2b060_2;
extern int g_00a2b060_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a2b060(void*);
struct O_00a2b060 { int m(int, void*, void*, void*, int); };
extern O_00a2b060 g_obj_00a2b060;
extern int g_tail_00a2b060;
void func_00a2b060()
{
    g_obj_00a2b060.m(184, (void*)&g_00a2b060_1, (void*)&g_00a2b060_2, (void*)&g_00a2b060_3, 0);
    tail_fn_00a2b060(&g_tail_00a2b060);
}