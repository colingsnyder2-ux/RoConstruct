// from server: 100% by colin
extern int g_009c3a50_0;
extern int g_009c3a50_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009c3a50(void*);
struct O_009c3a50 { int m(void*, void*, int, int, int); };
extern O_009c3a50 g_obj_009c3a50;
extern int g_tail_009c3a50;
void func_009c3a50()
{
    g_obj_009c3a50.m((void*)&g_009c3a50_0, (void*)&g_009c3a50_1, 308, 15, 0);
    tail_fn_009c3a50(&g_tail_009c3a50);
}