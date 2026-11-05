// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009c7370(void*, void*);
extern "C" void run_fn_009c7370(void);
extern "C" void tail_fn_009c7370(void*);
extern int g_a_009c7370;
extern int g_b_009c7370;
extern int g_c_009c7370;

void func_009c7370()
{
    init_fn_009c7370(&g_a_009c7370, &g_b_009c7370);
    run_fn_009c7370();
    tail_fn_009c7370(&g_c_009c7370);
}
