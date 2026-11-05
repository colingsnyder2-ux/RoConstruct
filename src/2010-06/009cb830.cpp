// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cb830(void*, void*);
extern "C" void run_fn_009cb830(void);
extern "C" void tail_fn_009cb830(void*);
extern int g_a_009cb830;
extern int g_b_009cb830;
extern int g_c_009cb830;

void func_009cb830()
{
    init_fn_009cb830(&g_a_009cb830, &g_b_009cb830);
    run_fn_009cb830();
    tail_fn_009cb830(&g_c_009cb830);
}
