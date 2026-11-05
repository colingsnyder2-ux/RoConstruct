// from server: 100% by colin
extern int g_0076cf30_0;
extern int g_0076cf30_1;
// roc-flags: /O2 /GS /EHsc /MD /Ob2 /Oy /GF
extern "C" void tail_fn_0076cf30(void*);
struct O_0076cf30 { int m(void*, void*, int, int); };
extern O_0076cf30 g_obj_0076cf30;
extern int g_tail_0076cf30;
void func_0076cf30()
{
    g_obj_0076cf30.m((void*)&g_0076cf30_0, (void*)&g_0076cf30_1, 233, 5);
    tail_fn_0076cf30(&g_tail_0076cf30);
}