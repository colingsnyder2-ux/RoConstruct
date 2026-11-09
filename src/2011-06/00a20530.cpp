// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00a20530(void*, void*);
extern "C" void run_fn_00a20530(void);
extern "C" void tail_fn_00a20530(void*);
extern int g_a_00a20530;
extern int g_b_00a20530;
extern int g_c_00a20530;

void func_00a20530()
{
    init_fn_00a20530(&g_a_00a20530, &g_b_00a20530);
    run_fn_00a20530();
    tail_fn_00a20530(&g_c_00a20530);
}
