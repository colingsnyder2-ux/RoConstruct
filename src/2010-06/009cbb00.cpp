// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cbb00(void*, void*);
extern "C" void run_fn_009cbb00(void);
extern "C" void tail_fn_009cbb00(void*);
extern int g_a_009cbb00;
extern int g_b_009cbb00;
extern int g_c_009cbb00;

void func_009cbb00()
{
    init_fn_009cbb00(&g_a_009cbb00, &g_b_009cbb00);
    run_fn_009cbb00();
    tail_fn_009cbb00(&g_c_009cbb00);
}
