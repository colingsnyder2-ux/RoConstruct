// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cb860(void*, void*);
extern "C" void run_fn_009cb860(void);
extern "C" void tail_fn_009cb860(void*);
extern int g_a_009cb860;
extern int g_b_009cb860;
extern int g_c_009cb860;

void func_009cb860()
{
    init_fn_009cb860(&g_a_009cb860, &g_b_009cb860);
    run_fn_009cb860();
    tail_fn_009cb860(&g_c_009cb860);
}
