// from server: 100% by colin
extern int g_009c7740_0;
extern int g_009c7740_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009c7740(void*);
struct O_009c7740 { int m(void*, void*, int, int, int); };
extern O_009c7740 g_obj_009c7740;
extern int g_tail_009c7740;
void func_009c7740()
{
    g_obj_009c7740.m((void*)&g_009c7740_0, (void*)&g_009c7740_1, 204, 15, 0);
    tail_fn_009c7740(&g_tail_009c7740);
}