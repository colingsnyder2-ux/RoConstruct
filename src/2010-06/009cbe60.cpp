// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cbe60(void*, void*);
extern "C" void run_fn_009cbe60(void);
extern "C" void tail_fn_009cbe60(void*);
extern int g_a_009cbe60;
extern int g_b_009cbe60;
extern int g_c_009cbe60;

void func_009cbe60()
{
    init_fn_009cbe60(&g_a_009cbe60, &g_b_009cbe60);
    run_fn_009cbe60();
    tail_fn_009cbe60(&g_c_009cbe60);
}
