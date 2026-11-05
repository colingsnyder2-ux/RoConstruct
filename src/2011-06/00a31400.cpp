// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a31400;
extern "C" int init_fn_00a31400(void*);
extern void* g_target_00a31400;
extern int g_value_00a31400;

void func_00a31400()
{
    if (g_ptr_00a31400)
        init_fn_00a31400(g_ptr_00a31400);
    g_target_00a31400 = &g_value_00a31400;
}
