// from server: 100% by colin
extern int g_007f1f10_0;
extern int g_007f1f10_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007f1f10(void*);
struct O_007f1f10 { int m(void*, void*, int, int); };
extern O_007f1f10 g_obj_007f1f10;
extern int g_tail_007f1f10;
void func_007f1f10()
{
    g_obj_007f1f10.m((void*)&g_007f1f10_0, (void*)&g_007f1f10_1, 322, 5);
    tail_fn_007f1f10(&g_tail_007f1f10);
}