// from server: 100% by colin
extern int g_009c7030_1;
extern int g_009c7030_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009c7030(void*);
struct O_009c7030 { int m(int, void*, void*, int, int); };
extern O_009c7030 g_obj_009c7030;
extern int g_tail_009c7030;
void func_009c7030()
{
    g_obj_009c7030.m(368, (void*)&g_009c7030_1, (void*)&g_009c7030_2, 0, 1);
    tail_fn_009c7030(&g_tail_009c7030);
}