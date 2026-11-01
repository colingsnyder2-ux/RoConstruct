// from server: 100% by colin
extern int g_00a22fd0_1;
extern int g_00a22fd0_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a22fd0(void*);
struct O_00a22fd0 { int m(int, void*, void*, int); };
extern O_00a22fd0 g_obj_00a22fd0;
extern int g_tail_00a22fd0;
void func_00a22fd0()
{
    g_obj_00a22fd0.m(588, (void*)&g_00a22fd0_1, (void*)&g_00a22fd0_2, 0);
    tail_fn_00a22fd0(&g_tail_00a22fd0);
}