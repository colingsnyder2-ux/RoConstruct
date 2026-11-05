// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cbb60(void*, void*);
extern "C" void run_fn_009cbb60(void);
extern "C" void tail_fn_009cbb60(void*);
extern int g_a_009cbb60;
extern int g_b_009cbb60;
extern int g_c_009cbb60;

void func_009cbb60()
{
    init_fn_009cbb60(&g_a_009cbb60, &g_b_009cbb60);
    run_fn_009cbb60();
    tail_fn_009cbb60(&g_c_009cbb60);
}
