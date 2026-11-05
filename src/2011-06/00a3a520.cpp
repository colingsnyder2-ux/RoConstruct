// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a3a520;
extern "C" int init_fn_00a3a520(void*);
extern void* g_target_00a3a520;
extern int g_value_00a3a520;

void func_00a3a520()
{
    if (g_ptr_00a3a520)
        init_fn_00a3a520(g_ptr_00a3a520);
    g_target_00a3a520 = &g_value_00a3a520;
}
