// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cbef0(void*, void*);
extern "C" void run_fn_009cbef0(void);
extern "C" void tail_fn_009cbef0(void*);
extern int g_a_009cbef0;
extern int g_b_009cbef0;
extern int g_c_009cbef0;

void func_009cbef0()
{
    init_fn_009cbef0(&g_a_009cbef0, &g_b_009cbef0);
    run_fn_009cbef0();
    tail_fn_009cbef0(&g_c_009cbef0);
}
