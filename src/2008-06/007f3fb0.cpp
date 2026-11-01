// from server: 100% by colin
extern int g_007f3fb0_0;
extern int g_007f3fb0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007f3fb0(void*);
struct O_007f3fb0 { int m(void*, void*, int, int); };
extern O_007f3fb0 g_obj_007f3fb0;
extern int g_tail_007f3fb0;
void func_007f3fb0()
{
    g_obj_007f3fb0.m((void*)&g_007f3fb0_0, (void*)&g_007f3fb0_1, 344, 5);
    tail_fn_007f3fb0(&g_tail_007f3fb0);
}