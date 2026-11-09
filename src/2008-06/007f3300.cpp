// from server: 100% by colin
extern int g_007f3300_0;
extern int g_007f3300_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007f3300(void*);
struct O_007f3300 { int m(void*, void*, int, int); };
extern O_007f3300 g_obj_007f3300;
extern int g_tail_007f3300;
void func_007f3300()
{
    g_obj_007f3300.m((void*)&g_007f3300_0, (void*)&g_007f3300_1, 313, 5);
    tail_fn_007f3300(&g_tail_007f3300);
}