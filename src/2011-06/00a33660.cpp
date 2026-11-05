// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a33660;
extern "C" int init_fn_00a33660(void*);
extern void* g_target_00a33660;
extern int g_value_00a33660;

void func_00a33660()
{
    if (g_ptr_00a33660)
        init_fn_00a33660(g_ptr_00a33660);
    g_target_00a33660 = &g_value_00a33660;
}
