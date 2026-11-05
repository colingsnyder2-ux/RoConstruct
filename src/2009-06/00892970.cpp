// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_00892970(void*, void*);
extern "C" void run_fn_00892970(void);
extern "C" void tail_fn_00892970(void*);
extern int g_a_00892970;
extern int g_b_00892970;
extern int g_c_00892970;

void func_00892970()
{
    init_fn_00892970(&g_a_00892970, &g_b_00892970);
    run_fn_00892970();
    tail_fn_00892970(&g_c_00892970);
}
