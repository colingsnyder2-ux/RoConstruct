// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a322e0;
extern "C" int init_fn_00a322e0(void*);
extern void* g_target_00a322e0;
extern int g_value_00a322e0;

void func_00a322e0()
{
    if (g_ptr_00a322e0)
        init_fn_00a322e0(g_ptr_00a322e0);
    g_target_00a322e0 = &g_value_00a322e0;
}
