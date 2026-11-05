// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a34950;
extern "C" int init_fn_00a34950(void*);
extern void* g_target_00a34950;
extern int g_value_00a34950;

void func_00a34950()
{
    if (g_ptr_00a34950)
        init_fn_00a34950(g_ptr_00a34950);
    g_target_00a34950 = &g_value_00a34950;
}
