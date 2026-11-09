// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a35210;
extern "C" int init_fn_00a35210(void*);
extern void* g_target_00a35210;
extern int g_value_00a35210;

void func_00a35210()
{
    if (g_ptr_00a35210)
        init_fn_00a35210(g_ptr_00a35210);
    g_target_00a35210 = &g_value_00a35210;
}
