// from server: 100% by colin
extern int g_007f1210_0;
extern int g_007f1210_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007f1210(void*);
struct O_007f1210 { int m(void*, void*, int, int); };
extern O_007f1210 g_obj_007f1210;
extern int g_tail_007f1210;
void func_007f1210()
{
    g_obj_007f1210.m((void*)&g_007f1210_0, (void*)&g_007f1210_1, 460, 4);
    tail_fn_007f1210(&g_tail_007f1210);
}