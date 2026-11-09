// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cc430(void*, void*);
extern "C" void run_fn_009cc430(void);
extern "C" void tail_fn_009cc430(void*);
extern int g_a_009cc430;
extern int g_b_009cc430;
extern int g_c_009cc430;

void func_009cc430()
{
    init_fn_009cc430(&g_a_009cc430, &g_b_009cc430);
    run_fn_009cc430();
    tail_fn_009cc430(&g_c_009cc430);
}
