// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cfa20(void*, void*);
extern "C" void run_fn_009cfa20(void);
extern "C" void tail_fn_009cfa20(void*);
extern int g_a_009cfa20;
extern int g_b_009cfa20;
extern int g_c_009cfa20;

void func_009cfa20()
{
    init_fn_009cfa20(&g_a_009cfa20, &g_b_009cfa20);
    run_fn_009cfa20();
    tail_fn_009cfa20(&g_c_009cfa20);
}
