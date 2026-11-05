// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009cbd40(void*, void*);
extern "C" void run_fn_009cbd40(void);
extern "C" void tail_fn_009cbd40(void*);
extern int g_a_009cbd40;
extern int g_b_009cbd40;
extern int g_c_009cbd40;

void func_009cbd40()
{
    init_fn_009cbd40(&g_a_009cbd40, &g_b_009cbd40);
    run_fn_009cbd40();
    tail_fn_009cbd40(&g_c_009cbd40);
}
