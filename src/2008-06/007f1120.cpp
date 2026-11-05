// from server: 100% by colin
extern int g_007f1120_0;
extern int g_007f1120_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007f1120(void*);
struct O_007f1120 { int m(void*, void*, int, int); };
extern O_007f1120 g_obj_007f1120;
extern int g_tail_007f1120;
void func_007f1120()
{
    g_obj_007f1120.m((void*)&g_007f1120_0, (void*)&g_007f1120_1, 440, 4);
    tail_fn_007f1120(&g_tail_007f1120);
}