// from server: 100% by colin
extern int g_007f5590_0;
extern int g_007f5590_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007f5590(void*);
struct O_007f5590 { int m(void*, void*, int, int); };
extern O_007f5590 g_obj_007f5590;
extern int g_tail_007f5590;
void func_007f5590()
{
    g_obj_007f5590.m((void*)&g_007f5590_0, (void*)&g_007f5590_1, 304, 5);
    tail_fn_007f5590(&g_tail_007f5590);
}