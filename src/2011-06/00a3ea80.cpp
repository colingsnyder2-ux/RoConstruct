// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a3ea80;
extern "C" int init_fn_00a3ea80(void*);
extern void* g_target_00a3ea80;
extern int g_value_00a3ea80;

void func_00a3ea80()
{
    if (g_ptr_00a3ea80)
        init_fn_00a3ea80(g_ptr_00a3ea80);
    g_target_00a3ea80 = &g_value_00a3ea80;
}
