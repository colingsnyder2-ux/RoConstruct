// from server: 100% by colin
extern int g_00a24d70_1;
extern int g_00a24d70_2;
extern int g_00a24d70_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a24d70(void*);
struct O_00a24d70 { int m(int, void*, void*, void*, int); };
extern O_00a24d70 g_obj_00a24d70;
extern int g_tail_00a24d70;
void func_00a24d70()
{
    g_obj_00a24d70.m(196, (void*)&g_00a24d70_1, (void*)&g_00a24d70_2, (void*)&g_00a24d70_3, 0);
    tail_fn_00a24d70(&g_tail_00a24d70);
}