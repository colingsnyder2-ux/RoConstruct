// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00a20200(void*, void*);
extern "C" void run_fn_00a20200(void);
extern "C" void tail_fn_00a20200(void*);
extern int g_a_00a20200;
extern int g_b_00a20200;
extern int g_c_00a20200;

void func_00a20200()
{
    init_fn_00a20200(&g_a_00a20200, &g_b_00a20200);
    run_fn_00a20200();
    tail_fn_00a20200(&g_c_00a20200);
}
