// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00a20230(void*, void*);
extern "C" void run_fn_00a20230(void);
extern "C" void tail_fn_00a20230(void*);
extern int g_a_00a20230;
extern int g_b_00a20230;
extern int g_c_00a20230;

void func_00a20230()
{
    init_fn_00a20230(&g_a_00a20230, &g_b_00a20230);
    run_fn_00a20230();
    tail_fn_00a20230(&g_c_00a20230);
}
