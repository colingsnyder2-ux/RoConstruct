// from server: 100% by colin
extern int g_00891480_0;
extern int g_00891480_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00891480(void*);
struct O_00891480 { int m(void*, void*, int, int); };
extern O_00891480 g_obj_00891480;
extern int g_tail_00891480;
void func_00891480()
{
    g_obj_00891480.m((void*)&g_00891480_0, (void*)&g_00891480_1, 400, 7);
    tail_fn_00891480(&g_tail_00891480);
}