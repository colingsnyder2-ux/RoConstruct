// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cbf20(void*, void*);
extern "C" void run_fn_009cbf20(void);
extern "C" void tail_fn_009cbf20(void*);
extern int g_a_009cbf20;
extern int g_b_009cbf20;
extern int g_c_009cbf20;

void func_009cbf20()
{
    init_fn_009cbf20(&g_a_009cbf20, &g_b_009cbf20);
    run_fn_009cbf20();
    tail_fn_009cbf20(&g_c_009cbf20);
}
