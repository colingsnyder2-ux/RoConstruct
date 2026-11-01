// from server: 100% by colin
extern int g_007f7d90_0;
extern int g_007f7d90_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007f7d90(void*);
struct O_007f7d90 { int m(void*, void*, int, int); };
extern O_007f7d90 g_obj_007f7d90;
extern int g_tail_007f7d90;
void func_007f7d90()
{
    g_obj_007f7d90.m((void*)&g_007f7d90_0, (void*)&g_007f7d90_1, 324, 5);
    tail_fn_007f7d90(&g_tail_007f7d90);
}