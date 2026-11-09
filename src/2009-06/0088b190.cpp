// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_0088b190(void*, void*);
extern "C" void run_fn_0088b190(void);
extern "C" void tail_fn_0088b190(void*);
extern int g_a_0088b190;
extern int g_b_0088b190;
extern int g_c_0088b190;

void func_0088b190()
{
    init_fn_0088b190(&g_a_0088b190, &g_b_0088b190);
    run_fn_0088b190();
    tail_fn_0088b190(&g_c_0088b190);
}
