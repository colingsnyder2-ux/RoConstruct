// from server: 100% by colin
extern int g_007f8100_0;
extern int g_007f8100_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007f8100(void*);
struct O_007f8100 { int m(void*, void*, int, int); };
extern O_007f8100 g_obj_007f8100;
extern int g_tail_007f8100;
void func_007f8100()
{
    g_obj_007f8100.m((void*)&g_007f8100_0, (void*)&g_007f8100_1, 396, 5);
    tail_fn_007f8100(&g_tail_007f8100);
}