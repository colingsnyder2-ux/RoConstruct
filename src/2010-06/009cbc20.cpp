// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cbc20(void*, void*);
extern "C" void run_fn_009cbc20(void);
extern "C" void tail_fn_009cbc20(void*);
extern int g_a_009cbc20;
extern int g_b_009cbc20;
extern int g_c_009cbc20;

void func_009cbc20()
{
    init_fn_009cbc20(&g_a_009cbc20, &g_b_009cbc20);
    run_fn_009cbc20();
    tail_fn_009cbc20(&g_c_009cbc20);
}
