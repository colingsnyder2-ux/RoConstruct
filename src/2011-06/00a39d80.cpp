// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a39d80;
extern "C" int init_fn_00a39d80(void*);
extern void* g_target_00a39d80;
extern int g_value_00a39d80;

void func_00a39d80()
{
    if (g_ptr_00a39d80)
        init_fn_00a39d80(g_ptr_00a39d80);
    g_target_00a39d80 = &g_value_00a39d80;
}
