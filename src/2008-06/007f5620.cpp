// from server: 100% by colin
extern int g_007f5620_0;
extern int g_007f5620_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007f5620(void*);
struct O_007f5620 { int m(void*, void*, int, int); };
extern O_007f5620 g_obj_007f5620;
extern int g_tail_007f5620;
void func_007f5620()
{
    g_obj_007f5620.m((void*)&g_007f5620_0, (void*)&g_007f5620_1, 313, 5);
    tail_fn_007f5620(&g_tail_007f5620);
}