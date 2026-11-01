// from server: 100% by colin
extern int g_00a1c1b0_0;
extern int g_00a1c1b0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a1c1b0(void*);
struct O_00a1c1b0 { int m(void*, void*, int, int, int); };
extern O_00a1c1b0 g_obj_00a1c1b0;
extern int g_tail_00a1c1b0;
void func_00a1c1b0()
{
    g_obj_00a1c1b0.m((void*)&g_00a1c1b0_0, (void*)&g_00a1c1b0_1, 163, 16, 0);
    tail_fn_00a1c1b0(&g_tail_00a1c1b0);
}