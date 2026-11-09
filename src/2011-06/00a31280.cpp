// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a31280;
extern "C" int init_fn_00a31280(void*);
extern void* g_target_00a31280;
extern int g_value_00a31280;

void func_00a31280()
{
    if (g_ptr_00a31280)
        init_fn_00a31280(g_ptr_00a31280);
    g_target_00a31280 = &g_value_00a31280;
}
