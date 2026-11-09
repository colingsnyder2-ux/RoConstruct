// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_0088b550(void*, void*);
extern "C" void run_fn_0088b550(void);
extern "C" void tail_fn_0088b550(void*);
extern int g_a_0088b550;
extern int g_b_0088b550;
extern int g_c_0088b550;

void func_0088b550()
{
    init_fn_0088b550(&g_a_0088b550, &g_b_0088b550);
    run_fn_0088b550();
    tail_fn_0088b550(&g_c_0088b550);
}
