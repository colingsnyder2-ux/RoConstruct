// from server: 100% by colin
extern int g_007f1c20_0;
extern int g_007f1c20_1;
extern int g_007f1c20_2;
extern int g_007f1c20_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007f1c20(void*);
struct O_007f1c20 { int m(void*, void*, void*, void*); };
extern O_007f1c20 g_obj_007f1c20;
extern int g_tail_007f1c20;
void func_007f1c20()
{
    g_obj_007f1c20.m((void*)&g_007f1c20_0, (void*)&g_007f1c20_1, (void*)&g_007f1c20_2, (void*)&g_007f1c20_3);
    tail_fn_007f1c20(&g_tail_007f1c20);
}