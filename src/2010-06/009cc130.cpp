// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cc130(void*, void*);
extern "C" void run_fn_009cc130(void);
extern "C" void tail_fn_009cc130(void*);
extern int g_a_009cc130;
extern int g_b_009cc130;
extern int g_c_009cc130;

void func_009cc130()
{
    init_fn_009cc130(&g_a_009cc130, &g_b_009cc130);
    run_fn_009cc130();
    tail_fn_009cc130(&g_c_009cc130);
}
