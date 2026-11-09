// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00a16440(void*, void*);
extern "C" void run_fn_00a16440(void);
extern "C" void tail_fn_00a16440(void*);
extern int g_a_00a16440;
extern int g_b_00a16440;
extern int g_c_00a16440;

void func_00a16440()
{
    init_fn_00a16440(&g_a_00a16440, &g_b_00a16440);
    run_fn_00a16440();
    tail_fn_00a16440(&g_c_00a16440);
}
