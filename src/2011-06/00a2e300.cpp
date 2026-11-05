// from server: 100% by colin
extern int g_00a2e300_1;
extern int g_00a2e300_2;
extern int g_00a2e300_3;
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_00a2e300(void*);
struct O_00a2e300 { int m(int, void*, void*, void*, int); };
extern O_00a2e300 g_obj_00a2e300;
extern int g_tail_00a2e300;
void func_00a2e300()
{
    g_obj_00a2e300.m(156, (void*)&g_00a2e300_1, (void*)&g_00a2e300_2, (void*)&g_00a2e300_3, 2);
    tail_fn_00a2e300(&g_tail_00a2e300);
}