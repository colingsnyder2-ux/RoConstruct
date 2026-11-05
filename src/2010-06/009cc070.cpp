// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cc070(void*, void*);
extern "C" void run_fn_009cc070(void);
extern "C" void tail_fn_009cc070(void*);
extern int g_a_009cc070;
extern int g_b_009cc070;
extern int g_c_009cc070;

void func_009cc070()
{
    init_fn_009cc070(&g_a_009cc070, &g_b_009cc070);
    run_fn_009cc070();
    tail_fn_009cc070(&g_c_009cc070);
}
