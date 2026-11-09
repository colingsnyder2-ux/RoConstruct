// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009c4290(void*, void*);
extern "C" void run_fn_009c4290(void);
extern "C" void tail_fn_009c4290(void*);
extern int g_a_009c4290;
extern int g_b_009c4290;
extern int g_c_009c4290;

void func_009c4290()
{
    init_fn_009c4290(&g_a_009c4290, &g_b_009c4290);
    run_fn_009c4290();
    tail_fn_009c4290(&g_c_009c4290);
}
