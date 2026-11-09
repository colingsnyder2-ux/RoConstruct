// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_00a33620;
extern "C" int init_fn_00a33620(void*);
extern void* g_target_00a33620;
extern int g_value_00a33620;

void func_00a33620()
{
    if (g_ptr_00a33620)
        init_fn_00a33620(g_ptr_00a33620);
    g_target_00a33620 = &g_value_00a33620;
}
