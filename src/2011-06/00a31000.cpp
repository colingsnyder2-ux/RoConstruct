// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a31000;
extern "C" int init_fn_00a31000(void*);
extern void* g_target_00a31000;
extern int g_value_00a31000;

void func_00a31000()
{
    if (g_ptr_00a31000)
        init_fn_00a31000(g_ptr_00a31000);
    g_target_00a31000 = &g_value_00a31000;
}
