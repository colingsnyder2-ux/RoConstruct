// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cc370(void*, void*);
extern "C" void run_fn_009cc370(void);
extern "C" void tail_fn_009cc370(void*);
extern int g_a_009cc370;
extern int g_b_009cc370;
extern int g_c_009cc370;

void func_009cc370()
{
    init_fn_009cc370(&g_a_009cc370, &g_b_009cc370);
    run_fn_009cc370();
    tail_fn_009cc370(&g_c_009cc370);
}
