// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00a18f20(void*, void*);
extern "C" void run_fn_00a18f20(void);
extern "C" void tail_fn_00a18f20(void*);
extern int g_a_00a18f20;
extern int g_b_00a18f20;
extern int g_c_00a18f20;

void func_00a18f20()
{
    init_fn_00a18f20(&g_a_00a18f20, &g_b_00a18f20);
    run_fn_00a18f20();
    tail_fn_00a18f20(&g_c_00a18f20);
}
