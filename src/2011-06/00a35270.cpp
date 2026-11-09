// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a35270;
extern "C" int init_fn_00a35270(void*);
extern void* g_target_00a35270;
extern int g_value_00a35270;

void func_00a35270()
{
    if (g_ptr_00a35270)
        init_fn_00a35270(g_ptr_00a35270);
    g_target_00a35270 = &g_value_00a35270;
}
