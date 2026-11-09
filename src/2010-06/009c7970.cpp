// from server: 100% by colin
extern int g_009c7970_0;
extern int g_009c7970_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_009c7970(void*);
struct O_009c7970 { int m(void*, void*, int, int, int); };
extern O_009c7970 g_obj_009c7970;
extern int g_tail_009c7970;
void func_009c7970()
{
    g_obj_009c7970.m((void*)&g_009c7970_0, (void*)&g_009c7970_1, 153, 15, 0);
    tail_fn_009c7970(&g_tail_009c7970);
}