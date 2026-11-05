// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a31420;
extern "C" int init_fn_00a31420(void*);
extern void* g_target_00a31420;
extern int g_value_00a31420;

void func_00a31420()
{
    if (g_ptr_00a31420)
        init_fn_00a31420(g_ptr_00a31420);
    g_target_00a31420 = &g_value_00a31420;
}
