// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a39fc0;
extern "C" int init_fn_00a39fc0(void*);
extern void* g_target_00a39fc0;
extern int g_value_00a39fc0;

void func_00a39fc0()
{
    if (g_ptr_00a39fc0)
        init_fn_00a39fc0(g_ptr_00a39fc0);
    g_target_00a39fc0 = &g_value_00a39fc0;
}
