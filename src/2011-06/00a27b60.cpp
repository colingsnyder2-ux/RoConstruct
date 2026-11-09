// from server: 100% by colin
extern int g_00a27b60_1;
extern int g_00a27b60_2;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a27b60(void*);
struct O_00a27b60 { int m(int, void*, void*, int); };
extern O_00a27b60 g_obj_00a27b60;
extern int g_tail_00a27b60;
void func_00a27b60()
{
    g_obj_00a27b60.m(148, (void*)&g_00a27b60_1, (void*)&g_00a27b60_2, 0);
    tail_fn_00a27b60(&g_tail_00a27b60);
}