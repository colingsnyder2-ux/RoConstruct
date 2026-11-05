// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cc190(void*, void*);
extern "C" void run_fn_009cc190(void);
extern "C" void tail_fn_009cc190(void*);
extern int g_a_009cc190;
extern int g_b_009cc190;
extern int g_c_009cc190;

void func_009cc190()
{
    init_fn_009cc190(&g_a_009cc190, &g_b_009cc190);
    run_fn_009cc190();
    tail_fn_009cc190(&g_c_009cc190);
}
