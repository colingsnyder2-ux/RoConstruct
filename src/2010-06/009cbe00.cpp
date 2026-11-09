// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cbe00(void*, void*);
extern "C" void run_fn_009cbe00(void);
extern "C" void tail_fn_009cbe00(void*);
extern int g_a_009cbe00;
extern int g_b_009cbe00;
extern int g_c_009cbe00;

void func_009cbe00()
{
    init_fn_009cbe00(&g_a_009cbe00, &g_b_009cbe00);
    run_fn_009cbe00();
    tail_fn_009cbe00(&g_c_009cbe00);
}
