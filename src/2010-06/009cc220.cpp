// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cc220(void*, void*);
extern "C" void run_fn_009cc220(void);
extern "C" void tail_fn_009cc220(void*);
extern int g_a_009cc220;
extern int g_b_009cc220;
extern int g_c_009cc220;

void func_009cc220()
{
    init_fn_009cc220(&g_a_009cc220, &g_b_009cc220);
    run_fn_009cc220();
    tail_fn_009cc220(&g_c_009cc220);
}
