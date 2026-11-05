// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_0088db70(void*, void*);
extern "C" void run_fn_0088db70(void);
extern "C" void tail_fn_0088db70(void*);
extern int g_a_0088db70;
extern int g_b_0088db70;
extern int g_c_0088db70;

void func_0088db70()
{
    init_fn_0088db70(&g_a_0088db70, &g_b_0088db70);
    run_fn_0088db70();
    tail_fn_0088db70(&g_c_0088db70);
}
