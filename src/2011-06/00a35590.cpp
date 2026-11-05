// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a35590;
extern "C" int init_fn_00a35590(void*);
extern void* g_target_00a35590;
extern int g_value_00a35590;

void func_00a35590()
{
    if (g_ptr_00a35590)
        init_fn_00a35590(g_ptr_00a35590);
    g_target_00a35590 = &g_value_00a35590;
}
