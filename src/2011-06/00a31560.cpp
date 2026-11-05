// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a31560;
extern "C" int init_fn_00a31560(void*);
extern void* g_target_00a31560;
extern int g_value_00a31560;

void func_00a31560()
{
    if (g_ptr_00a31560)
        init_fn_00a31560(g_ptr_00a31560);
    g_target_00a31560 = &g_value_00a31560;
}
