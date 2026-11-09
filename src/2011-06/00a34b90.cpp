// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a34b90;
extern "C" int init_fn_00a34b90(void*);
extern void* g_target_00a34b90;
extern int g_value_00a34b90;

void func_00a34b90()
{
    if (g_ptr_00a34b90)
        init_fn_00a34b90(g_ptr_00a34b90);
    g_target_00a34b90 = &g_value_00a34b90;
}
