// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a34530;
extern "C" int init_fn_00a34530(void*);
extern void* g_target_00a34530;
extern int g_value_00a34530;

void func_00a34530()
{
    if (g_ptr_00a34530)
        init_fn_00a34530(g_ptr_00a34530);
    g_target_00a34530 = &g_value_00a34530;
}
