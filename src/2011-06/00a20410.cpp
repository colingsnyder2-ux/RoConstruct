// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00a20410(void*, void*);
extern "C" void run_fn_00a20410(void);
extern "C" void tail_fn_00a20410(void*);
extern int g_a_00a20410;
extern int g_b_00a20410;
extern int g_c_00a20410;

void func_00a20410()
{
    init_fn_00a20410(&g_a_00a20410, &g_b_00a20410);
    run_fn_00a20410();
    tail_fn_00a20410(&g_c_00a20410);
}
