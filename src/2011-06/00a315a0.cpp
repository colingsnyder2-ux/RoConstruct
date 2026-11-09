// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a315a0;
extern "C" int init_fn_00a315a0(void*);
extern void* g_target_00a315a0;
extern int g_value_00a315a0;

void func_00a315a0()
{
    if (g_ptr_00a315a0)
        init_fn_00a315a0(g_ptr_00a315a0);
    g_target_00a315a0 = &g_value_00a315a0;
}
