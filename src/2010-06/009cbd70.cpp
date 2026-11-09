// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cbd70(void*, void*);
extern "C" void run_fn_009cbd70(void);
extern "C" void tail_fn_009cbd70(void*);
extern int g_a_009cbd70;
extern int g_b_009cbd70;
extern int g_c_009cbd70;

void func_009cbd70()
{
    init_fn_009cbd70(&g_a_009cbd70, &g_b_009cbd70);
    run_fn_009cbd70();
    tail_fn_009cbd70(&g_c_009cbd70);
}
