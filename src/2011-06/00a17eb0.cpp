// from server: 100% by colin
extern int g_00a17eb0_0;
extern int g_00a17eb0_1;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a17eb0(void*);
struct O_00a17eb0 { int m(void*, void*, int, int, int); };
extern O_00a17eb0 g_obj_00a17eb0;
extern int g_tail_00a17eb0;
void func_00a17eb0()
{
    g_obj_00a17eb0.m((void*)&g_00a17eb0_0, (void*)&g_00a17eb0_1, 360, 2, 0);
    tail_fn_00a17eb0(&g_tail_00a17eb0);
}