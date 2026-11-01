// from server: 100% by colin
extern int g_007f1f40_0;
extern int g_007f1f40_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007f1f40(void*);
struct O_007f1f40 { int m(void*, void*, int, int); };
extern O_007f1f40 g_obj_007f1f40;
extern int g_tail_007f1f40;
void func_007f1f40()
{
    g_obj_007f1f40.m((void*)&g_007f1f40_0, (void*)&g_007f1f40_1, 323, 5);
    tail_fn_007f1f40(&g_tail_007f1f40);
}