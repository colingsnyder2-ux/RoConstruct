// from server: 100% by colin
extern int g_0076f5a0_0;
extern int g_0076f5a0_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0076f5a0(void*);
struct O_0076f5a0 { int m(void*, void*, int, int); };
extern O_0076f5a0 g_obj_0076f5a0;
extern int g_tail_0076f5a0;
void func_0076f5a0()
{
    g_obj_0076f5a0.m((void*)&g_0076f5a0_0, (void*)&g_0076f5a0_1, 247, 5);
    tail_fn_0076f5a0(&g_tail_0076f5a0);
}