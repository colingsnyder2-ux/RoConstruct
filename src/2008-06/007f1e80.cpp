// from server: 100% by colin
extern int g_007f1e80_0;
extern int g_007f1e80_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007f1e80(void*);
struct O_007f1e80 { int m(void*, void*, int, int); };
extern O_007f1e80 g_obj_007f1e80;
extern int g_tail_007f1e80;
void func_007f1e80()
{
    g_obj_007f1e80.m((void*)&g_007f1e80_0, (void*)&g_007f1e80_1, 304, 5);
    tail_fn_007f1e80(&g_tail_007f1e80);
}