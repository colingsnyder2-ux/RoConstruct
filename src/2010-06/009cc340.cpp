// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cc340(void*, void*);
extern "C" void run_fn_009cc340(void);
extern "C" void tail_fn_009cc340(void*);
extern int g_a_009cc340;
extern int g_b_009cc340;
extern int g_c_009cc340;

void func_009cc340()
{
    init_fn_009cc340(&g_a_009cc340, &g_b_009cc340);
    run_fn_009cc340();
    tail_fn_009cc340(&g_c_009cc340);
}
