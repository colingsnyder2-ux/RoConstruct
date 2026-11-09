// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a39d60;
extern "C" int init_fn_00a39d60(void*);
extern void* g_target_00a39d60;
extern int g_value_00a39d60;

void func_00a39d60()
{
    if (g_ptr_00a39d60)
        init_fn_00a39d60(g_ptr_00a39d60);
    g_target_00a39d60 = &g_value_00a39d60;
}
