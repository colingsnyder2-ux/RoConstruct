// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00a16650(void*, void*);
extern "C" void run_fn_00a16650(void);
extern "C" void tail_fn_00a16650(void*);
extern int g_a_00a16650;
extern int g_b_00a16650;
extern int g_c_00a16650;

void func_00a16650()
{
    init_fn_00a16650(&g_a_00a16650, &g_b_00a16650);
    run_fn_00a16650();
    tail_fn_00a16650(&g_c_00a16650);
}
