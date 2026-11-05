// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cb950(void*, void*);
extern "C" void run_fn_009cb950(void);
extern "C" void tail_fn_009cb950(void*);
extern int g_a_009cb950;
extern int g_b_009cb950;
extern int g_c_009cb950;

void func_009cb950()
{
    init_fn_009cb950(&g_a_009cb950, &g_b_009cb950);
    run_fn_009cb950();
    tail_fn_009cb950(&g_c_009cb950);
}
