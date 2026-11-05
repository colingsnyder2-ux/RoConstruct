// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cb680(void*, void*);
extern "C" void run_fn_009cb680(void);
extern "C" void tail_fn_009cb680(void*);
extern int g_a_009cb680;
extern int g_b_009cb680;
extern int g_c_009cb680;

void func_009cb680()
{
    init_fn_009cb680(&g_a_009cb680, &g_b_009cb680);
    run_fn_009cb680();
    tail_fn_009cb680(&g_c_009cb680);
}
