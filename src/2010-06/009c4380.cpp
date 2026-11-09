// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009c4380(void*, void*);
extern "C" void run_fn_009c4380(void);
extern "C" void tail_fn_009c4380(void*);
extern int g_a_009c4380;
extern int g_b_009c4380;
extern int g_c_009c4380;

void func_009c4380()
{
    init_fn_009c4380(&g_a_009c4380, &g_b_009c4380);
    run_fn_009c4380();
    tail_fn_009c4380(&g_c_009c4380);
}
