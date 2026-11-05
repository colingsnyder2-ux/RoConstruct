// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00a206b0(void*, void*);
extern "C" void run_fn_00a206b0(void);
extern "C" void tail_fn_00a206b0(void*);
extern int g_a_00a206b0;
extern int g_b_00a206b0;
extern int g_c_00a206b0;

void func_00a206b0()
{
    init_fn_00a206b0(&g_a_00a206b0, &g_b_00a206b0);
    run_fn_00a206b0();
    tail_fn_00a206b0(&g_c_00a206b0);
}
