// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_008853d0(void*, void*);
extern "C" void run_fn_008853d0(void);
extern "C" void tail_fn_008853d0(void*);
extern int g_a_008853d0;
extern int g_b_008853d0;
extern int g_c_008853d0;

void func_008853d0()
{
    init_fn_008853d0(&g_a_008853d0, &g_b_008853d0);
    run_fn_008853d0();
    tail_fn_008853d0(&g_c_008853d0);
}
