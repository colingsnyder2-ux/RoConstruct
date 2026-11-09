// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cb980(void*, void*);
extern "C" void run_fn_009cb980(void);
extern "C" void tail_fn_009cb980(void*);
extern int g_a_009cb980;
extern int g_b_009cb980;
extern int g_c_009cb980;

void func_009cb980()
{
    init_fn_009cb980(&g_a_009cb980, &g_b_009cb980);
    run_fn_009cb980();
    tail_fn_009cb980(&g_c_009cb980);
}
