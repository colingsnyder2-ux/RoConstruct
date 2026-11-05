// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a32300;
extern "C" int init_fn_00a32300(void*);
extern void* g_target_00a32300;
extern int g_value_00a32300;

void func_00a32300()
{
    if (g_ptr_00a32300)
        init_fn_00a32300(g_ptr_00a32300);
    g_target_00a32300 = &g_value_00a32300;
}
