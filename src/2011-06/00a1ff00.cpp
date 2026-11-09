// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00a1ff00(void*, void*);
extern "C" void run_fn_00a1ff00(void);
extern "C" void tail_fn_00a1ff00(void*);
extern int g_a_00a1ff00;
extern int g_b_00a1ff00;
extern int g_c_00a1ff00;

void func_00a1ff00()
{
    init_fn_00a1ff00(&g_a_00a1ff00, &g_b_00a1ff00);
    run_fn_00a1ff00();
    tail_fn_00a1ff00(&g_c_00a1ff00);
}
