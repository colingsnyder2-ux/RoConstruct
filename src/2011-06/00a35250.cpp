// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a35250;
extern "C" int init_fn_00a35250(void*);
extern void* g_target_00a35250;
extern int g_value_00a35250;

void func_00a35250()
{
    if (g_ptr_00a35250)
        init_fn_00a35250(g_ptr_00a35250);
    g_target_00a35250 = &g_value_00a35250;
}
