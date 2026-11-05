// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a34490;
extern "C" int init_fn_00a34490(void*);
extern void* g_target_00a34490;
extern int g_value_00a34490;

void func_00a34490()
{
    if (g_ptr_00a34490)
        init_fn_00a34490(g_ptr_00a34490);
    g_target_00a34490 = &g_value_00a34490;
}
