// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a31020;
extern "C" int init_fn_00a31020(void*);
extern void* g_target_00a31020;
extern int g_value_00a31020;

void func_00a31020()
{
    if (g_ptr_00a31020)
        init_fn_00a31020(g_ptr_00a31020);
    g_target_00a31020 = &g_value_00a31020;
}
