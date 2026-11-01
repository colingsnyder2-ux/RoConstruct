// from server: 100% by colin
extern int g_00a27e20_1;
extern int g_00a27e20_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a27e20(void*);
struct O_00a27e20 { int m(int, void*, void*, int); };
extern O_00a27e20 g_obj_00a27e20;
extern int g_tail_00a27e20;
void func_00a27e20()
{
    g_obj_00a27e20.m(192, (void*)&g_00a27e20_1, (void*)&g_00a27e20_2, 0);
    tail_fn_00a27e20(&g_tail_00a27e20);
}