// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cba40(void*, void*);
extern "C" void run_fn_009cba40(void);
extern "C" void tail_fn_009cba40(void*);
extern int g_a_009cba40;
extern int g_b_009cba40;
extern int g_c_009cba40;

void func_009cba40()
{
    init_fn_009cba40(&g_a_009cba40, &g_b_009cba40);
    run_fn_009cba40();
    tail_fn_009cba40(&g_c_009cba40);
}
