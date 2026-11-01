// from server: 100% by colin
extern int g_007f10c0_0;
extern int g_007f10c0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007f10c0(void*);
struct O_007f10c0 { int m(void*, void*, int, int); };
extern O_007f10c0 g_obj_007f10c0;
extern int g_tail_007f10c0;
void func_007f10c0()
{
    g_obj_007f10c0.m((void*)&g_007f10c0_0, (void*)&g_007f10c0_1, 432, 4);
    tail_fn_007f10c0(&g_tail_007f10c0);
}