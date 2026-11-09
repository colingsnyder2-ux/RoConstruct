// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a3b100;
extern "C" int init_fn_00a3b100(void*);
extern void* g_target_00a3b100;
extern int g_value_00a3b100;

void func_00a3b100()
{
    if (g_ptr_00a3b100)
        init_fn_00a3b100(g_ptr_00a3b100);
    g_target_00a3b100 = &g_value_00a3b100;
}
