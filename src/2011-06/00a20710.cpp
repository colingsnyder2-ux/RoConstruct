// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00a20710(void*, void*);
extern "C" void run_fn_00a20710(void);
extern "C" void tail_fn_00a20710(void*);
extern int g_a_00a20710;
extern int g_b_00a20710;
extern int g_c_00a20710;

void func_00a20710()
{
    init_fn_00a20710(&g_a_00a20710, &g_b_00a20710);
    run_fn_00a20710();
    tail_fn_00a20710(&g_c_00a20710);
}
