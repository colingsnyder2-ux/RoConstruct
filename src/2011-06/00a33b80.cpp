// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a33b80;
extern "C" int init_fn_00a33b80(void*);
extern void* g_target_00a33b80;
extern int g_value_00a33b80;

void func_00a33b80()
{
    if (g_ptr_00a33b80)
        init_fn_00a33b80(g_ptr_00a33b80);
    g_target_00a33b80 = &g_value_00a33b80;
}
