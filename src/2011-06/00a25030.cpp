// from server: 100% by colin
extern int g_00a25030_1;
extern int g_00a25030_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a25030(void*);
struct O_00a25030 { int m(int, void*, void*, int); };
extern O_00a25030 g_obj_00a25030;
extern int g_tail_00a25030;
void func_00a25030()
{
    g_obj_00a25030.m(192, (void*)&g_00a25030_1, (void*)&g_00a25030_2, 0);
    tail_fn_00a25030(&g_tail_00a25030);
}