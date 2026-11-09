// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a33760;
extern "C" int init_fn_00a33760(void*);
extern void* g_target_00a33760;
extern int g_value_00a33760;

void func_00a33760()
{
    if (g_ptr_00a33760)
        init_fn_00a33760(g_ptr_00a33760);
    g_target_00a33760 = &g_value_00a33760;
}
