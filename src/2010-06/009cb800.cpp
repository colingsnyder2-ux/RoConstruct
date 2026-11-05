// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cb800(void*, void*);
extern "C" void run_fn_009cb800(void);
extern "C" void tail_fn_009cb800(void*);
extern int g_a_009cb800;
extern int g_b_009cb800;
extern int g_c_009cb800;

void func_009cb800()
{
    init_fn_009cb800(&g_a_009cb800, &g_b_009cb800);
    run_fn_009cb800();
    tail_fn_009cb800(&g_c_009cb800);
}
