// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a39f40;
extern "C" int init_fn_00a39f40(void*);
extern void* g_target_00a39f40;
extern int g_value_00a39f40;

void func_00a39f40()
{
    if (g_ptr_00a39f40)
        init_fn_00a39f40(g_ptr_00a39f40);
    g_target_00a39f40 = &g_value_00a39f40;
}
