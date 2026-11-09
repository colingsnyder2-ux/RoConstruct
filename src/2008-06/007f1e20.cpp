// from server: 100% by colin
extern int g_007f1e20_0;
extern int g_007f1e20_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007f1e20(void*);
struct O_007f1e20 { int m(void*, void*, int, int); };
extern O_007f1e20 g_obj_007f1e20;
extern int g_tail_007f1e20;
void func_007f1e20()
{
    g_obj_007f1e20.m((void*)&g_007f1e20_0, (void*)&g_007f1e20_1, 306, 5);
    tail_fn_007f1e20(&g_tail_007f1e20);
}