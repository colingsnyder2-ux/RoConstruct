// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cb620(void*, void*);
extern "C" void run_fn_009cb620(void);
extern "C" void tail_fn_009cb620(void*);
extern int g_a_009cb620;
extern int g_b_009cb620;
extern int g_c_009cb620;

void func_009cb620()
{
    init_fn_009cb620(&g_a_009cb620, &g_b_009cb620);
    run_fn_009cb620();
    tail_fn_009cb620(&g_c_009cb620);
}
