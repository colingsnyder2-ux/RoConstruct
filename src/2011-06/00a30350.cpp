// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a30350;
extern "C" int init_fn_00a30350(void*);
extern void* g_target_00a30350;
extern int g_value_00a30350;

void func_00a30350()
{
    if (g_ptr_00a30350)
        init_fn_00a30350(g_ptr_00a30350);
    g_target_00a30350 = &g_value_00a30350;
}
