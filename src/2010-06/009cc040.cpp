// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cc040(void*, void*);
extern "C" void run_fn_009cc040(void);
extern "C" void tail_fn_009cc040(void*);
extern int g_a_009cc040;
extern int g_b_009cc040;
extern int g_c_009cc040;

void func_009cc040()
{
    init_fn_009cc040(&g_a_009cc040, &g_b_009cc040);
    run_fn_009cc040();
    tail_fn_009cc040(&g_c_009cc040);
}
