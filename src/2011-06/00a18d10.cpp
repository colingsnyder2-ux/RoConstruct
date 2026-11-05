// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00a18d10(void*, void*);
extern "C" void run_fn_00a18d10(void);
extern "C" void tail_fn_00a18d10(void*);
extern int g_a_00a18d10;
extern int g_b_00a18d10;
extern int g_c_00a18d10;

void func_00a18d10()
{
    init_fn_00a18d10(&g_a_00a18d10, &g_b_00a18d10);
    run_fn_00a18d10();
    tail_fn_00a18d10(&g_c_00a18d10);
}
