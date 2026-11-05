// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00a20980(void*, void*);
extern "C" void run_fn_00a20980(void);
extern "C" void tail_fn_00a20980(void*);
extern int g_a_00a20980;
extern int g_b_00a20980;
extern int g_c_00a20980;

void func_00a20980()
{
    init_fn_00a20980(&g_a_00a20980, &g_b_00a20980);
    run_fn_00a20980();
    tail_fn_00a20980(&g_c_00a20980);
}
