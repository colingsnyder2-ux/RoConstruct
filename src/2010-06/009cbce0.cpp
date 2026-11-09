// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cbce0(void*, void*);
extern "C" void run_fn_009cbce0(void);
extern "C" void tail_fn_009cbce0(void*);
extern int g_a_009cbce0;
extern int g_b_009cbce0;
extern int g_c_009cbce0;

void func_009cbce0()
{
    init_fn_009cbce0(&g_a_009cbce0, &g_b_009cbce0);
    run_fn_009cbce0();
    tail_fn_009cbce0(&g_c_009cbce0);
}
