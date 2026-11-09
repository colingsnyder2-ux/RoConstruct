// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cc310(void*, void*);
extern "C" void run_fn_009cc310(void);
extern "C" void tail_fn_009cc310(void*);
extern int g_a_009cc310;
extern int g_b_009cc310;
extern int g_c_009cc310;

void func_009cc310()
{
    init_fn_009cc310(&g_a_009cc310, &g_b_009cc310);
    run_fn_009cc310();
    tail_fn_009cc310(&g_c_009cc310);
}
