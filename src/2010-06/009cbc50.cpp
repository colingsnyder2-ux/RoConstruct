// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cbc50(void*, void*);
extern "C" void run_fn_009cbc50(void);
extern "C" void tail_fn_009cbc50(void*);
extern int g_a_009cbc50;
extern int g_b_009cbc50;
extern int g_c_009cbc50;

void func_009cbc50()
{
    init_fn_009cbc50(&g_a_009cbc50, &g_b_009cbc50);
    run_fn_009cbc50();
    tail_fn_009cbc50(&g_c_009cbc50);
}
