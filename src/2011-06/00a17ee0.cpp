// from server: 100% by colin
extern int g_00a17ee0_1;
extern int g_00a17ee0_2;
extern int g_00a17ee0_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a17ee0(void*);
struct O_00a17ee0 { int m(int, void*, void*, void*, int); };
extern O_00a17ee0 g_obj_00a17ee0;
extern int g_tail_00a17ee0;
void func_00a17ee0()
{
    g_obj_00a17ee0.m(328, (void*)&g_00a17ee0_1, (void*)&g_00a17ee0_2, (void*)&g_00a17ee0_3, 0);
    tail_fn_00a17ee0(&g_tail_00a17ee0);
}