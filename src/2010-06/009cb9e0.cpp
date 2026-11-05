// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cb9e0(void*, void*);
extern "C" void run_fn_009cb9e0(void);
extern "C" void tail_fn_009cb9e0(void*);
extern int g_a_009cb9e0;
extern int g_b_009cb9e0;
extern int g_c_009cb9e0;

void func_009cb9e0()
{
    init_fn_009cb9e0(&g_a_009cb9e0, &g_b_009cb9e0);
    run_fn_009cb9e0();
    tail_fn_009cb9e0(&g_c_009cb9e0);
}
