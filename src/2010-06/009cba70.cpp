// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cba70(void*, void*);
extern "C" void run_fn_009cba70(void);
extern "C" void tail_fn_009cba70(void*);
extern int g_a_009cba70;
extern int g_b_009cba70;
extern int g_c_009cba70;

void func_009cba70()
{
    init_fn_009cba70(&g_a_009cba70, &g_b_009cba70);
    run_fn_009cba70();
    tail_fn_009cba70(&g_c_009cba70);
}
