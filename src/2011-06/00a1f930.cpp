// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00a1f930(void*, void*);
extern "C" void run_fn_00a1f930(void);
extern "C" void tail_fn_00a1f930(void*);
extern int g_a_00a1f930;
extern int g_b_00a1f930;
extern int g_c_00a1f930;

void func_00a1f930()
{
    init_fn_00a1f930(&g_a_00a1f930, &g_b_00a1f930);
    run_fn_00a1f930();
    tail_fn_00a1f930(&g_c_00a1f930);
}
