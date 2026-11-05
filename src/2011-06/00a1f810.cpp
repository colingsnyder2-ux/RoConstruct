// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00a1f810(void*, void*);
extern "C" void run_fn_00a1f810(void);
extern "C" void tail_fn_00a1f810(void*);
extern int g_a_00a1f810;
extern int g_b_00a1f810;
extern int g_c_00a1f810;

void func_00a1f810()
{
    init_fn_00a1f810(&g_a_00a1f810, &g_b_00a1f810);
    run_fn_00a1f810();
    tail_fn_00a1f810(&g_c_00a1f810);
}
