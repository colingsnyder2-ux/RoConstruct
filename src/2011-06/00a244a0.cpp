// from server: 100% by colin
extern int g_00a244a0_0;
extern int g_00a244a0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a244a0(void*);
struct O_00a244a0 { int m(void*, void*, int, int, int); };
extern O_00a244a0 g_obj_00a244a0;
extern int g_tail_00a244a0;
void func_00a244a0()
{
    g_obj_00a244a0.m((void*)&g_00a244a0_0, (void*)&g_00a244a0_1, 180, 31, 0);
    tail_fn_00a244a0(&g_tail_00a244a0);
}