// from server: 100% by colin
extern int g_00a2d3a0_0;
extern int g_00a2d3a0_1;
extern int g_00a2d3a0_2;
extern int g_00a2d3a0_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a2d3a0(void*);
struct O_00a2d3a0 { int m(void*, void*, void*, void*, int); };
extern O_00a2d3a0 g_obj_00a2d3a0;
extern int g_tail_00a2d3a0;
void func_00a2d3a0()
{
    g_obj_00a2d3a0.m((void*)&g_00a2d3a0_0, (void*)&g_00a2d3a0_1, (void*)&g_00a2d3a0_2, (void*)&g_00a2d3a0_3, 31);
    tail_fn_00a2d3a0(&g_tail_00a2d3a0);
}