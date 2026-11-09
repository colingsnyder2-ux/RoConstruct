// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009c7490(void*, void*);
extern "C" void run_fn_009c7490(void);
extern "C" void tail_fn_009c7490(void*);
extern int g_a_009c7490;
extern int g_b_009c7490;
extern int g_c_009c7490;

void func_009c7490()
{
    init_fn_009c7490(&g_a_009c7490, &g_b_009c7490);
    run_fn_009c7490();
    tail_fn_009c7490(&g_c_009c7490);
}
