// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00a20680(void*, void*);
extern "C" void run_fn_00a20680(void);
extern "C" void tail_fn_00a20680(void*);
extern int g_a_00a20680;
extern int g_b_00a20680;
extern int g_c_00a20680;

void func_00a20680()
{
    init_fn_00a20680(&g_a_00a20680, &g_b_00a20680);
    run_fn_00a20680();
    tail_fn_00a20680(&g_c_00a20680);
}
