// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a34ed0;
extern "C" int init_fn_00a34ed0(void*);
extern void* g_target_00a34ed0;
extern int g_value_00a34ed0;

void func_00a34ed0()
{
    if (g_ptr_00a34ed0)
        init_fn_00a34ed0(g_ptr_00a34ed0);
    g_target_00a34ed0 = &g_value_00a34ed0;
}
