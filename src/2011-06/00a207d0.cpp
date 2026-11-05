// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00a207d0(void*, void*);
extern "C" void run_fn_00a207d0(void);
extern "C" void tail_fn_00a207d0(void*);
extern int g_a_00a207d0;
extern int g_b_00a207d0;
extern int g_c_00a207d0;

void func_00a207d0()
{
    init_fn_00a207d0(&g_a_00a207d0, &g_b_00a207d0);
    run_fn_00a207d0();
    tail_fn_00a207d0(&g_c_00a207d0);
}
