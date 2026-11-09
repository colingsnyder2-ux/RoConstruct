// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cc250(void*, void*);
extern "C" void run_fn_009cc250(void);
extern "C" void tail_fn_009cc250(void*);
extern int g_a_009cc250;
extern int g_b_009cc250;
extern int g_c_009cc250;

void func_009cc250()
{
    init_fn_009cc250(&g_a_009cc250, &g_b_009cc250);
    run_fn_009cc250();
    tail_fn_009cc250(&g_c_009cc250);
}
