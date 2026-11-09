// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009c7400(void*, void*);
extern "C" void run_fn_009c7400(void);
extern "C" void tail_fn_009c7400(void*);
extern int g_a_009c7400;
extern int g_b_009c7400;
extern int g_c_009c7400;

void func_009c7400()
{
    init_fn_009c7400(&g_a_009c7400, &g_b_009c7400);
    run_fn_009c7400();
    tail_fn_009c7400(&g_c_009c7400);
}
