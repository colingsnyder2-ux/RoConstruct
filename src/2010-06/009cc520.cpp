// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cc520(void*, void*);
extern "C" void run_fn_009cc520(void);
extern "C" void tail_fn_009cc520(void*);
extern int g_a_009cc520;
extern int g_b_009cc520;
extern int g_c_009cc520;

void func_009cc520()
{
    init_fn_009cc520(&g_a_009cc520, &g_b_009cc520);
    run_fn_009cc520();
    tail_fn_009cc520(&g_c_009cc520);
}
