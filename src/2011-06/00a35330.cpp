// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a35330;
extern "C" int init_fn_00a35330(void*);
extern void* g_target_00a35330;
extern int g_value_00a35330;

void func_00a35330()
{
    if (g_ptr_00a35330)
        init_fn_00a35330(g_ptr_00a35330);
    g_target_00a35330 = &g_value_00a35330;
}
