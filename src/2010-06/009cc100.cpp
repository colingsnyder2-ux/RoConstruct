// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cc100(void*, void*);
extern "C" void run_fn_009cc100(void);
extern "C" void tail_fn_009cc100(void*);
extern int g_a_009cc100;
extern int g_b_009cc100;
extern int g_c_009cc100;

void func_009cc100()
{
    init_fn_009cc100(&g_a_009cc100, &g_b_009cc100);
    run_fn_009cc100();
    tail_fn_009cc100(&g_c_009cc100);
}
