// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cc400(void*, void*);
extern "C" void run_fn_009cc400(void);
extern "C" void tail_fn_009cc400(void*);
extern int g_a_009cc400;
extern int g_b_009cc400;
extern int g_c_009cc400;

void func_009cc400()
{
    init_fn_009cc400(&g_a_009cc400, &g_b_009cc400);
    run_fn_009cc400();
    tail_fn_009cc400(&g_c_009cc400);
}
