// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_0088b490(void*, void*);
extern "C" void run_fn_0088b490(void);
extern "C" void tail_fn_0088b490(void*);
extern int g_a_0088b490;
extern int g_b_0088b490;
extern int g_c_0088b490;

void func_0088b490()
{
    init_fn_0088b490(&g_a_0088b490, &g_b_0088b490);
    run_fn_0088b490();
    tail_fn_0088b490(&g_c_0088b490);
}
