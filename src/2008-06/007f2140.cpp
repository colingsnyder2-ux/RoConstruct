// from server: 100% by colin
extern int g_007f2140_0;
extern int g_007f2140_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_007f2140(void*);
struct O_007f2140 { int m(void*, void*, int, int); };
extern O_007f2140 g_obj_007f2140;
extern int g_tail_007f2140;
void func_007f2140()
{
    g_obj_007f2140.m((void*)&g_007f2140_0, (void*)&g_007f2140_1, 336, 5);
    tail_fn_007f2140(&g_tail_007f2140);
}