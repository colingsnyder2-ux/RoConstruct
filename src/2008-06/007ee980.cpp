// from server: 100% by colin
extern int g_007ee980_0;
extern int g_007ee980_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007ee980(void*);
struct O_007ee980 { int m(void*, void*, int, int); };
extern O_007ee980 g_obj_007ee980;
extern int g_tail_007ee980;
void func_007ee980()
{
    g_obj_007ee980.m((void*)&g_007ee980_0, (void*)&g_007ee980_1, 304, 5);
    tail_fn_007ee980(&g_tail_007ee980);
}