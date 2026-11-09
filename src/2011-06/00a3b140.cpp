// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a3b140;
extern "C" int init_fn_00a3b140(void*);
extern void* g_target_00a3b140;
extern int g_value_00a3b140;

void func_00a3b140()
{
    if (g_ptr_00a3b140)
        init_fn_00a3b140(g_ptr_00a3b140);
    g_target_00a3b140 = &g_value_00a3b140;
}
