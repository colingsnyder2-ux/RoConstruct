// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009c41a0(void*, void*);
extern "C" void run_fn_009c41a0(void);
extern "C" void tail_fn_009c41a0(void*);
extern int g_a_009c41a0;
extern int g_b_009c41a0;
extern int g_c_009c41a0;

void func_009c41a0()
{
    init_fn_009c41a0(&g_a_009c41a0, &g_b_009c41a0);
    run_fn_009c41a0();
    tail_fn_009c41a0(&g_c_009c41a0);
}
