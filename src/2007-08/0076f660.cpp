// from server: 100% by colin
extern int g_0076f660_0;
extern int g_0076f660_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0076f660(void*);
struct O_0076f660 { int m(void*, void*, int, int); };
extern O_0076f660 g_obj_0076f660;
extern int g_tail_0076f660;
void func_0076f660()
{
    g_obj_0076f660.m((void*)&g_0076f660_0, (void*)&g_0076f660_1, 260, 5);
    tail_fn_0076f660(&g_tail_0076f660);
}