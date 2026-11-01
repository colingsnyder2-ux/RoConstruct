// from server: 100% by colin
extern int g_009cf330_0;
extern int g_009cf330_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009cf330(void*);
struct O_009cf330 { int m(void*, void*, int, int, int); };
extern O_009cf330 g_obj_009cf330;
extern int g_tail_009cf330;
void func_009cf330()
{
    g_obj_009cf330.m((void*)&g_009cf330_0, (void*)&g_009cf330_1, 300, 9, 2);
    tail_fn_009cf330(&g_tail_009cf330);
}