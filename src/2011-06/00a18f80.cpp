// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00a18f80(void*, void*);
extern "C" void run_fn_00a18f80(void);
extern "C" void tail_fn_00a18f80(void*);
extern int g_a_00a18f80;
extern int g_b_00a18f80;
extern int g_c_00a18f80;

void func_00a18f80()
{
    init_fn_00a18f80(&g_a_00a18f80, &g_b_00a18f80);
    run_fn_00a18f80();
    tail_fn_00a18f80(&g_c_00a18f80);
}
