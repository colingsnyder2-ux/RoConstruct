// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_009c7430(void*, void*);
extern "C" void run_fn_009c7430(void);
extern "C" void tail_fn_009c7430(void*);
extern int g_a_009c7430;
extern int g_b_009c7430;
extern int g_c_009c7430;

void func_009c7430()
{
    init_fn_009c7430(&g_a_009c7430, &g_b_009c7430);
    run_fn_009c7430();
    tail_fn_009c7430(&g_c_009c7430);
}
