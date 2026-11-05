// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a34e50;
extern "C" int init_fn_00a34e50(void*);
extern void* g_target_00a34e50;
extern int g_value_00a34e50;

void func_00a34e50()
{
    if (g_ptr_00a34e50)
        init_fn_00a34e50(g_ptr_00a34e50);
    g_target_00a34e50 = &g_value_00a34e50;
}
