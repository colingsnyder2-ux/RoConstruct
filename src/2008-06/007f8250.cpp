// from server: 100% by colin
extern int g_007f8250_0;
extern int g_007f8250_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007f8250(void*);
struct O_007f8250 { int m(void*, void*, int, int); };
extern O_007f8250 g_obj_007f8250;
extern int g_tail_007f8250;
void func_007f8250()
{
    g_obj_007f8250.m((void*)&g_007f8250_0, (void*)&g_007f8250_1, 348, 5);
    tail_fn_007f8250(&g_tail_007f8250);
}