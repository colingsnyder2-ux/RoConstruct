// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00a16560(void*, void*);
extern "C" void run_fn_00a16560(void);
extern "C" void tail_fn_00a16560(void*);
extern int g_a_00a16560;
extern int g_b_00a16560;
extern int g_c_00a16560;

void func_00a16560()
{
    init_fn_00a16560(&g_a_00a16560, &g_b_00a16560);
    run_fn_00a16560();
    tail_fn_00a16560(&g_c_00a16560);
}
