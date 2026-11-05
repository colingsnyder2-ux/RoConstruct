// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a30310;
extern "C" int init_fn_00a30310(void*);
extern void* g_target_00a30310;
extern int g_value_00a30310;

void func_00a30310()
{
    if (g_ptr_00a30310)
        init_fn_00a30310(g_ptr_00a30310);
    g_target_00a30310 = &g_value_00a30310;
}
