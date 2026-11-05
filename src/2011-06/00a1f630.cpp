// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00a1f630(void*, void*);
extern "C" void run_fn_00a1f630(void);
extern "C" void tail_fn_00a1f630(void*);
extern int g_a_00a1f630;
extern int g_b_00a1f630;
extern int g_c_00a1f630;

void func_00a1f630()
{
    init_fn_00a1f630(&g_a_00a1f630, &g_b_00a1f630);
    run_fn_00a1f630();
    tail_fn_00a1f630(&g_c_00a1f630);
}
