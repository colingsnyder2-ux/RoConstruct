// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cbf80(void*, void*);
extern "C" void run_fn_009cbf80(void);
extern "C" void tail_fn_009cbf80(void*);
extern int g_a_009cbf80;
extern int g_b_009cbf80;
extern int g_c_009cbf80;

void func_009cbf80()
{
    init_fn_009cbf80(&g_a_009cbf80, &g_b_009cbf80);
    run_fn_009cbf80();
    tail_fn_009cbf80(&g_c_009cbf80);
}
