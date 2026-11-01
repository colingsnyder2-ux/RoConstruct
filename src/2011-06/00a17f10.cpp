// from server: 100% by colin
extern int g_00a17f10_1;
extern int g_00a17f10_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a17f10(void*);
struct O_00a17f10 { int m(int, void*, void*, int); };
extern O_00a17f10 g_obj_00a17f10;
extern int g_tail_00a17f10;
void func_00a17f10()
{
    g_obj_00a17f10.m(332, (void*)&g_00a17f10_1, (void*)&g_00a17f10_2, 0);
    tail_fn_00a17f10(&g_tail_00a17f10);
}