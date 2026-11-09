// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a32400;
extern "C" int init_fn_00a32400(void*);
extern void* g_target_00a32400;
extern int g_value_00a32400;

void func_00a32400()
{
    if (g_ptr_00a32400)
        init_fn_00a32400(g_ptr_00a32400);
    g_target_00a32400 = &g_value_00a32400;
}
