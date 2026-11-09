// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00a16410(void*, void*);
extern "C" void run_fn_00a16410(void);
extern "C" void tail_fn_00a16410(void*);
extern int g_a_00a16410;
extern int g_b_00a16410;
extern int g_c_00a16410;

void func_00a16410()
{
    init_fn_00a16410(&g_a_00a16410, &g_b_00a16410);
    run_fn_00a16410();
    tail_fn_00a16410(&g_c_00a16410);
}
