// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cc010(void*, void*);
extern "C" void run_fn_009cc010(void);
extern "C" void tail_fn_009cc010(void*);
extern int g_a_009cc010;
extern int g_b_009cc010;
extern int g_c_009cc010;

void func_009cc010()
{
    init_fn_009cc010(&g_a_009cc010, &g_b_009cc010);
    run_fn_009cc010();
    tail_fn_009cc010(&g_c_009cc010);
}
