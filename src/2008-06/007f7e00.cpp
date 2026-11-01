// from server: 100% by colin
extern int g_007f7e00_0;
extern int g_007f7e00_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007f7e00(void*);
struct O_007f7e00 { int m(void*, void*, int, int); };
extern O_007f7e00 g_obj_007f7e00;
extern int g_tail_007f7e00;
void func_007f7e00()
{
    g_obj_007f7e00.m((void*)&g_007f7e00_0, (void*)&g_007f7e00_1, 344, 5);
    tail_fn_007f7e00(&g_tail_007f7e00);
}