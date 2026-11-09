// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_008852e0(void*, void*);
extern "C" void run_fn_008852e0(void);
extern "C" void tail_fn_008852e0(void*);
extern int g_a_008852e0;
extern int g_b_008852e0;
extern int g_c_008852e0;

void func_008852e0()
{
    init_fn_008852e0(&g_a_008852e0, &g_b_008852e0);
    run_fn_008852e0();
    tail_fn_008852e0(&g_c_008852e0);
}
