// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cb740(void*, void*);
extern "C" void run_fn_009cb740(void);
extern "C" void tail_fn_009cb740(void*);
extern int g_a_009cb740;
extern int g_b_009cb740;
extern int g_c_009cb740;

void func_009cb740()
{
    init_fn_009cb740(&g_a_009cb740, &g_b_009cb740);
    run_fn_009cb740();
    tail_fn_009cb740(&g_c_009cb740);
}
