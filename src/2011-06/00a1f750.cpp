// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00a1f750(void*, void*);
extern "C" void run_fn_00a1f750(void);
extern "C" void tail_fn_00a1f750(void*);
extern int g_a_00a1f750;
extern int g_b_00a1f750;
extern int g_c_00a1f750;

void func_00a1f750()
{
    init_fn_00a1f750(&g_a_00a1f750, &g_b_00a1f750);
    run_fn_00a1f750();
    tail_fn_00a1f750(&g_c_00a1f750);
}
