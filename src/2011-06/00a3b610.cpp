// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a3b610;
extern "C" int init_fn_00a3b610(void*);
extern void* g_target_00a3b610;
extern int g_value_00a3b610;

void func_00a3b610()
{
    if (g_ptr_00a3b610)
        init_fn_00a3b610(g_ptr_00a3b610);
    g_target_00a3b610 = &g_value_00a3b610;
}
