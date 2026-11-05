// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cb920(void*, void*);
extern "C" void run_fn_009cb920(void);
extern "C" void tail_fn_009cb920(void*);
extern int g_a_009cb920;
extern int g_b_009cb920;
extern int g_c_009cb920;

void func_009cb920()
{
    init_fn_009cb920(&g_a_009cb920, &g_b_009cb920);
    run_fn_009cb920();
    tail_fn_009cb920(&g_c_009cb920);
}
