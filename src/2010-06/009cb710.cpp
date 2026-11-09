// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cb710(void*, void*);
extern "C" void run_fn_009cb710(void);
extern "C" void tail_fn_009cb710(void*);
extern int g_a_009cb710;
extern int g_b_009cb710;
extern int g_c_009cb710;

void func_009cb710()
{
    init_fn_009cb710(&g_a_009cb710, &g_b_009cb710);
    run_fn_009cb710();
    tail_fn_009cb710(&g_c_009cb710);
}
